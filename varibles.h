#define map_width 16384
#define map_height 4

GLfloat world_map[map_width][map_height];/*=
        {
                {1.0,1.0,1.0},
                {1.0,2.0,2.0},
                {1.0,3.0,3.0},
                {1.0,4.0,2.0},
                {1.0,5.0,2.0},
                {1.0,6.0,2.0},
                {1.0,7.0,2.0},
                {1.0,8.0,2.0},
                {1.0,9.0,2.0},
                {1.0,10.0,2.0},
                {1.0,11.0,2.0},
                {1.0,12.0,2.0},
                {3.0,1.0,2.0},
                {3.0,2.0,2.0},
                {3.0,3.0,2.0},
                {3.0,4.0,2.0},
                {3.0,5.0,2.0},
                {3.0,6.0,2.0},
                {3.0,7.0,2.0},
                {3.0,8.0,2.0},
                {3.0,9.0,2.0},
                {3.0,10.0,2.0},





        };*/

bool keys[256], specialkeys[256];
int water;

int mouse_button,mouse_x,mouse_y;





GLfloat player_x = 180.0, player_y = -180.0,player_z=80.0;

float camera_distance=3.0,camera_theta=90.0,camera_fi=0.0;
float fov=45.0;
GLuint v,f,p,w,pv,pf,buldingHgh,buildingLow,buildingSmall;