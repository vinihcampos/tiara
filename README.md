# TIARa - This is a Raster 

TIARa is simple rasterizer to draw shapes, like: points, lines, polygons, polylines and arcs.

## Features

* [x] Points
* [ ] Lines
    * [x] DDA (thickness 1-N)
    * [x] Bresenham (thickness 1-N)
    * [ ] Xiaolin
* [x] Arcs
    * [x] Circle (thickness 1-N)
    * [x] Semicircle (thickness 1-N, degree 0-360)
* [ ] Fills
    * [x] Polygon scan-line
    * [x] Boundary fill
    * [ ] Flood fill
* [x] Antialiasing
    * [x] Convolution (with gamma correction)
* [x] Palettes
* [x] Viewport

## Manual

<details><summary> The description below shows how to draw using tiara xml descriptor.</summary>

### scene

The default scenes produces an image with 800wx600h, with black background and have the following structure:
```xml
<scene>  
</scene>
```
#### Parameters
- **width**: Width of image [OPTIONAL]
- **height**: Height of image [OPTIONAL]
- **name**: File path of image result [OPTIONAL]
- **centerx** : Define the center of image on axis-x [OPTIONAL]
- **centery** : Define the center of image on axis-y [OPTIONAL]

#### Example

```xml
<scene width="300" height="200" name="scenes/images/circle" centerx="150" centery="100">
</scene>
```
### point

Paint a pixel (R,G,B) of a scene with specific color.

#### Parameters
- **x**: Point on axis-x
- **y**: Point on axis-y
- **color**: Color of the point [OPTIONAL]

#### Example

```xml
<scene width="10" height="10" name="scenes/images/point">
  <point x="5" y="5" color="yellow"/>
</scene>
```

### line

Create a line between two points with specific color.

#### Parameters
- **x1**: First point on axis-x
- **y1**: First point on axis-y
- **x2**: Second point on axis-x
- **y2** : Second point on axis-y
- **color** : Color of the line [OPTIONAL]
- **thickness** : Define the thickness of line [OPTIONAL]
- **alg** : Define the line algorithm implementation (dda or bresenham) [OPTIONAL]

#### Example

```xml
<scene width="300" height="200" name="scenes/images/line">
  <line x1="10" y1="10" x2="150" y2="150" color="red" thickness="10" alg="Bresenham"/>
</scene>
```

### polygon

Create a closed segment of lines, where the last point connects to the first.

#### Parameters
- **border-color**\*: Define the color of border. [OPTIONAL]
- **fill-color**\*: Define the inside color. [OPTIONAL]
- **thickness** : Define the thickness of polygon border [OPTIONAL]
- **p** : Define a vertex of polygon [OPTIONAL]

\*: These parameter are optional, but it is necessary provide at least one of them.

#### Example

```xml
<scene name="scenes/images/polygon">
  <polygon border-color="white" fill-color="red" thickness="1">
		<p x="600" y="200"/>
		<p x="750" y="180"/>
		<p x="400" y="500"/>
		<p x="790" y="350"/>
	</polygon>
</scene>
```

### polyline

Create a unclosed segment of lines. But it may be closed if the first and the last points are equals.

#### Parameters
- **color**: Define the color of border. [OPTIONAL]
- **thickness** : Define the thickness border [OPTIONAL]
- **p** : Define a vertex of polygon [OPTIONAL]

#### Example

```xml
<scene width="300" height="200" name="scenes/images/polyline">
	<polyline color="red" thickness="1">
		<p x="75" y="200"/>
		<p x="75" y="50"/>
		<p x="100" y="100"/>
		<p x="200" y="100"/>
		<p x="225" y="50"/>
		<p x="225" y="200"/>
	</polyline>
</scene>
```

### arc

Create circles or arcs between 0-360 degrees.

#### Parameters
- **x**: Center point on axis-x
- **y**: Center point on axis-y
- **radius**: Define the the radius of arc
- **border-color**\*: Define the color of border. [OPTIONAL]
- **fill-color**\*: Define the inside color. [OPTIONAL]
- **thickness** : Define the thickness of polygon border [OPTIONAL]
- **trigger** : Define a point to fire the filling. [OPTIONAL]

#### Example

```xml
<scene width="300" height="200" name="scenes/images/arc" centerx="150" centery="100">
	<arc x="0" y="0" radius="20" border-color="olive" fill-color="purple" thickness="5">
		<trigger x="0" y="0"/>
	</arc>
</scene>
```
### pallete

Provides for the scene a color palette\* to use as names of colors.

\*: Each color of file has to be the following structure:
    [color_name] [r_color] [g_color] [b_color]

Ex:

```
red 255 0 0 
green 0 255 0
blue 0 0 255
```

#### Parameters
- **file**: File path of color palete

#### Example

```xml
<scene>
	<pallete file="palletes/paleta.txt"/>
</scene>
```
</details>

## Author

[![Vinicius Campos](https://avatars.githubusercontent.com/Vinihcampos?s=100)<br /><sub>Vinicius Campos</sub>](http://lattes.cnpq.br/4806707968253342)<br />[👀](https://github.com/Vinihcampos/tiara/commits?author=Vinihcampos)
| :---: | 

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE) file for details
