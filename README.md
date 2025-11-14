# MiniRT
![42](https://img.shields.io/badge/-42-black?style=for-the-badge&logo=42&logoColor=white) ![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white)

## Description

MiniRT generates a 3D image with realistic lighting using ray tracing technology.

### Content

description du parsing et des possibilité

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

## Visual Progress

### First Step
<img width="500" height="500" alt="MiniRT1" src="https://github.com/user-attachments/assets/b950ac49-de75-4dee-b29c-1505310700cc" />

At this stage, we have a visible sphere. Lighting is not yet implemented, but we've established the ray casting logic and distance calculation relative to the camera. There is also a principle of intersection with the sphere. If the ray has at least one possibility of intersection with the sphere, then a red pixel is placed there. For the math used ([Line–sphere intersection](https://en.wikipedia.org/wiki/Line%E2%80%93sphere_intersection)).

## Light and reflection
<img width="495" height="480" alt="Screenshot from 2025-10-07 13-08-27" src="https://github.com/user-attachments/assets/d59369af-0a1b-4077-aa26-21ae6012b350" />

To simulate reflection, we use the Phong model ([Phong reflection model](https://en.wikipedia.org/wiki/Phong_reflection_model)). To achieve this, we have 3 types of lighting. Ambient reflection assumes that each object is slightly illuminated regardless of light sources. Diffuse reflection simulates the light gradient based on the alignment between the light direction and the surface normal. Finally, there is specular reflection (the white highlight) which corresponds to the direct alignment between the reflected light and the viewer's eye.

## First Scene

<img width="994" height="492" alt="Screenshot from 2025-10-13 12-27-40" src="https://github.com/user-attachments/assets/3b201be1-6c17-4f40-b80e-4ec3afe02ed2" />

## Indirect light
<img width="967" height="483" alt="Screenshot from 2025-11-06 13-37-33" src="https://github.com/user-attachments/assets/db129110-dc3d-42df-87eb-f31a372268fb" />

The light source is positioned on the left, and the object on the right illuminates the right side of the left object through secondary light bounces.
This phenomenon allows certain areas to remain lit even when they are not directly exposed to the light source.
In the current implementation, light attenuation due to distance or the number of bounces is not taken into account, which results in indirect lighting being overly intense.
Nevertheless, the overall visual quality of the render is significantly improved.

The visible noise is due to the lack of rays at each bounce, and the colors are not very realistic because of the low number of bounces.

### Color bleeding
<img width="967" height="483" alt="Screenshot from 2025-11-06 13-36-12" src="https://github.com/user-attachments/assets/fd9c4303-95fe-4ea2-a767-f880dff5ac73" />

Indirect lighting also produces color bleeding, where the color of an object is reflected through light bounces and influences the appearance of nearby surfaces.
As with indirect lighting, the color bleeding effect appears stronger than expected because several physical attenuation factors have not yet been implemented.

## Shadow

For shadow rendering, we first create a ray that starts from a point on an object and heads toward the light source. This gives us a vector called the “**Shadow Ray**”. If this ray intersects another object along its path before reaching the light source, then the original point on the object is considered to be in shadow. Otherwise, it is in the light. We repeat this process for every point on all objects, and that’s how we obtain our shadows!

## Plane and cylindre and sphere

Adding objects follows the same basic pattern: we cast a ray into the scene and check whether it intersects an object.

**Sphere**: A sphere is a closed surface whose points are all located at the same distance from its center.

**Plane**: A plane is a flat, two-dimensional surface that extends infinitely. As a result, any ray cast toward it will hit the plane, unless the ray and the plane are parallel.

**Cylinder**: The cylinder is created in three steps. First, the cylinder we compute is infinitely long, so we need to give it a start value and an end value so that it has a well-defined height.
At this stage, the cylinder is still open, so we then need to add caps to close it, making it behave like a real cylinder.
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

## Resources 

- [the raytracer challenge de Jamis Buck](http://raytracerchallenge.com/)
- [Line–sphere intersection](https://en.wikipedia.org/wiki/Line%E2%80%93sphere_intersection)

## Contributors
[@njooris] (https://github.com/rayseur123)

[@dernst] (https://github.com/Ernst-Devan)

