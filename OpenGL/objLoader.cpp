#include "objLoader.h"


using namespace std;

namespace objLoader
{
 
    int loadObject(const char* filename)
    {
        std::vector<std::string*> coord;        
        std::vector<coordinate*> vertex;
        std::vector<face*> faces;
        std::vector<coordinate*> normals;       
        //open the .obj file
        std::ifstream in(filename);     
        //if not opened, exit with -1
        if(!in.is_open())       
        {
            std::cout << "Nor oepened" << std::endl;
            return -1;
        }
        char buf[256];
        //read in every line to coord
        while(!in.eof())
        {
            in.getline(buf,256);
            coord.push_back(new std::string(buf));
        }
        //check each coordinate and check what its for 
        for(int i=0;i<coord.size();i++)
        {
            //if # then its a comment
            if(coord[i]->c_str()[0]=='#') continue;
                  
            //if v then its a vector
            else if(coord[i]->c_str()[0]=='v' && coord[i]->c_str()[1]==' ') 
            {
                float tmpx,tmpy,tmpz;
                sscanf_s(coord[i]->c_str(),"v %f %f %f",&tmpx,&tmpy,&tmpz);     
                vertex.push_back(new coordinate(tmpx,tmpy,tmpz));      
            }
            
            //if vn then its a vector normal
            else if(coord[i]->c_str()[0]=='v' && coord[i]->c_str()[1]=='n')   
            {
                float tmpx,tmpy,tmpz;   //do the same thing
                sscanf_s(coord[i]->c_str(),"vn %f %f %f",&tmpx,&tmpy,&tmpz);
                normals.push_back(new coordinate(tmpx,tmpy,tmpz));     
            }
            //if f then its a face
            else if(coord[i]->c_str()[0]=='f')     
            {
                int a,b,c,d,e;
                if(count(coord[i]->begin(),coord[i]->end(),' ')==3)     //if it is a triangle (it has 3 space in it)
                {
                    sscanf_s(coord[i]->c_str(),"f %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b);
                        faces.push_back(new face(b,a,c,d));     //read in, and add to the end of the face list
                }else{
                        sscanf_s(coord[i]->c_str(),"f %d//%d %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b,&e,&b);
                        faces.push_back(new face(b,a,c,d,e));   //do the same, except we call another constructor, and we use different pattern
                }
            }
        }

        int num;        

        num=glGenLists(1);      
        glNewList(num,GL_COMPILE);     
        for(int i=0;i<faces.size();i++)
        {
            //if it's a quad draw a quad
            if(faces[i]->four)      
            {
                    glBegin(GL_QUADS);
                            
                            glNormal3f(normals[faces[i]->facenum-1]->x,normals[faces[i]->facenum-1]->y,normals[faces[i]->facenum-1]->z);
                            glVertex3f(vertex[faces[i]->faces[0]-1]->x,vertex[faces[i]->faces[0]-1]->y,vertex[faces[i]->faces[0]-1]->z);
                            glVertex3f(vertex[faces[i]->faces[1]-1]->x,vertex[faces[i]->faces[1]-1]->y,vertex[faces[i]->faces[1]-1]->z);
                            glVertex3f(vertex[faces[i]->faces[2]-1]->x,vertex[faces[i]->faces[2]-1]->y,vertex[faces[i]->faces[2]-1]->z);
                            glVertex3f(vertex[faces[i]->faces[3]-1]->x,vertex[faces[i]->faces[3]-1]->y,vertex[faces[i]->faces[3]-1]->z);
                    glEnd();
            }else{
                    glBegin(GL_TRIANGLES);
                            glNormal3f(normals[faces[i]->facenum-1]->x,normals[faces[i]->facenum-1]->y,normals[faces[i]->facenum-1]->z);
                            glVertex3f(vertex[faces[i]->faces[0]-1]->x,vertex[faces[i]->faces[0]-1]->y,vertex[faces[i]->faces[0]-1]->z);
                            glVertex3f(vertex[faces[i]->faces[1]-1]->x,vertex[faces[i]->faces[1]-1]->y,vertex[faces[i]->faces[1]-1]->z);
                            glVertex3f(vertex[faces[i]->faces[2]-1]->x,vertex[faces[i]->faces[2]-1]->y,vertex[faces[i]->faces[2]-1]->z);
                    glEnd();
            }
        }
        glEndList();

        //delete 
        for(int i=0;i<coord.size();i++)
                delete coord[i];
        for(int i=0;i<faces.size();i++)
                delete faces[i];
        for(int i=0;i<normals.size();i++)
                delete normals[i];
        for(int i=0;i<vertex.size();i++)
                delete vertex[i];
        return num;     //return id
    }
}