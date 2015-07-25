# vecmath
#### A simple math library for 3d development.

This library includes the following data structures:

1. _Vectors_
  * **_vec2_** - a two element vector
  * **_vec3_** - a three element vector
  * **_vec4_** - a four element vector
  * **_quat_** - a quaternion
  
3. _Matrices_ (column major)
  * **_mat2_** - a 2x2 matrix
  * **_mat3_** - a 3x3 matrix
  * **_mat4_** - a 4x4 matrix

## Usage
```cpp
    #include <vecmath/matrix.hpp>
    #include <vecmath/pi.hpp>
    
    //example to create a quick "player" transformation matrix
    vcm::vec3 player_pos{ 3, 6, 4 }; //position vector of player
    vcm::quat player_rot = vcm::angle_axis(45 * vcm::RAD, { 0, 1, 0 }); //rotation quaternion of player
    vcm::vec3 player_scale{ 1 }; //scalar vector of player; short for vcm::vec3(1.0f, 1.0f, 1.0f)
    
    //create matrix from translation, rotation, and scale
    vcm::mat4 player_transform = vcm::compose(player_pos, player_rot, player_scale);
    
    //and if you wanted to, say, upload the matrix to OpenGL for example...
    glUniformMatrix4fv(..., &player_transform[0][0]);
