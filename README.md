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

## shadow

To cast shadow, we recreate one by one a new ray named "shadow ray" wich start from each point on object and end to the light, we named the magnitude of this vector v. Also we cast the ray and detect if it hit an other object until the light.
In case of an object is present we considered that the point is in shadow, in the other case the point is in the light.

Pour l'affichage des ombres, On recree dans un premier temps un ray qui part d'un point d'un object et qui se dirige vers la source de lumiere. Ainsi on obtient un vecteur qu'on nomme "Shadow Ray" auquel on stock sa magnitude dans une variable v.
Si ce ray croise un autre object durant son chemin avant d'atteindre la source lumineuse on en convient que le point initial de l'objet est donc dans l'ombres. Dans le cas contraire il est dans la lumiere. On repete ce processus pour chaque point de tout les objets et on obtient notre ombre !

## Plane and cylindre and sphere

L'ajout des objets ce fait tous en suivant le meme paterne de base, On lance un rayon dans notre scene et on observe si il intersecte un objet.

Sphere: La sphere est une surface ferme dont tout les points sont situe a une meme distance du centre.

Plane: Le plane est une surface plate en 2 dimensions qui s'etend indefiniment. De ce faite tout les rayons envoyer vont toucher le plane sauf si ce dernier et le planes sont parallele.

Cylindre: Le cylindre ce fait en 3 etapes, Dans un premier temps le cylindre qu'on catch est infiniment long alors il nous faut lui attribuer une valeur de debut et une valeur de fin pour qu'il est une height bien definis.
Notre cylindre est actuellement ouvert alors il nous font desormais lui rajouter des caps pour qu'il soit fermer comme un vrai cylindre.

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

