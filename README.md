# MiniRT
![42](https://img.shields.io/badge/-42-black?style=for-the-badge&logo=42&logoColor=white) ![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white)

## Description

MiniRT generates a 3D image with realistic lighting using ray tracing technology.

## Installation
### Download the repository
```
- git clone https://github.com/rayseur123/MiniRT.git MiniRT
```
### Access and compile
```
- cd MiniRT
- make
```
### Launch the program
```
- executer avec './miniRT'
```

## Resources 

- [the raytracer challenge de Jamis Buck](http://raytracerchallenge.com/)
- [Line–sphere intersection](https://en.wikipedia.org/wiki/Line%E2%80%93sphere_intersection)

## Visual Progress

### First Step
<img width="500" height="500" alt="MiniRT1" src="https://github.com/user-attachments/assets/b950ac49-de75-4dee-b29c-1505310700cc" />

At this stage, we have a visible sphere. Lighting is not yet implemented, but we've established the ray casting logic and distance calculation relative to the camera. There is also a principle of intersection with the sphere. If the ray has at least one possibility of intersection with the sphere, then a red pixel is placed there. For the math used ([Line–sphere intersection](https://en.wikipedia.org/wiki/Line%E2%80%93sphere_intersection)).

## Lumiere et reflection
<img width="495" height="480" alt="Screenshot from 2025-10-07 13-08-27" src="https://github.com/user-attachments/assets/d59369af-0a1b-4077-aa26-21ae6012b350" />

To simulate reflection, we use the Phong model ([Phong reflection model](https://en.wikipedia.org/wiki/Phong_reflection_model)). To achieve this, we have 3 types of lighting. Ambient reflection assumes that each object is slightly illuminated regardless of light sources. Diffuse reflection simulates the light gradient based on the alignment between the light direction and the surface normal. Finally, there is specular reflection (the white highlight) which corresponds to the direct alignment between the reflected light and the viewer's eye.

## Logic Implementation

### Tuples

To handle coordinates in 3D space, we use tuples, which are divided into two types: **points** and **vectors**.

Both have x, y, z coordinates (left-handed system). To differentiate them, they include a fourth component 'w' that is set to either 1 (for points) or 0 (for vectors).

Various functions for manipulating tuples can be found in: `srcs/manage_scene/tuple/`

### Transformation Matrices

We use 4x4 matrices to apply transformations to our objects, including translation, scaling, rotation, and more. All transformations are handled through matrices.

Matrix manipulation functions are located in: `srcs/manage_scene/matrice/`

**Key concept: The Identity Matrix**

The identity matrix, when multiplied with a tuple, leaves the tuple unchanged (equivalent to multiplying by 1).

We build a global transformation matrix by successively applying individual transformation matrices (scaling, rotation, translation, etc.).

**Important principle:** Instead of transforming objects, we transform the rays (our viewpoint). This is mathematically equivalent but more efficient:
- Scaling an object up = moving closer to it
- Moving an object down = elevating our viewpoint

This approach simplifies calculations while producing identical results.

## Contributors
[@njooris : https://github.com/rayseur123](https://github.com/rayseur123)

[@dernst : https://github.com/rayseur123](https://github.com/Ernst-Devan)

