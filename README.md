*This project has been created as part of the 42 curriculum by rabi-aka[, ankim].*

**Description**

	*Goal*

	This project's aim is to create a 3D environment in which a player, incarnated by a POV, can move and rotate.

	*Overview*

	To do so, the use of the MLX is mandatory. The map must be surronded by walls, and only one player spawning in one of the cardinal direction can exist.

	First we parsed the file used to create the environment. For the info part :
		-a valid color for the floor and the ceiling (2)
		-a valid path for each texture of wall (4)
		-no other informations are allowed (but empty lines are valid)
	For the map part :
		-it must be enclosed by wall
		-contains only one player incarnated by a spawing direction (E, W, S or N for the cardinal points)

	To complete the project we must used the concept of raycasting and calculate and project rays that start from the player position and correct orientation with the DDA (Digital Differential Analyzer) algorithm to find the walls to hit.
	With the wall distance we can determine the height and portion of the walls and then render a 3D effect and apply the correct texture.

**Instruction**

1. Make
2. Execute ./cub3D followed by a map (in ./map/valid or ./map/invalid)
3. Move through the maze by using W/A/S/D to move forward, backward or on the side and the left and right arrow to move the camera's angle

**Resources**

*Articles*

https://fr.wikipedia.org/wiki/Raycasting
https://lodev.org/cgtutor/raycasting.html
https://42-fran-byte-f94097.gitlab.io/docs/cub3d/cub3d-approach-en/#/
https://nathaan.me/projects/cub3d
https://medium.com/@PradumnaVerma/mastering-computer-graphics-understanding-digital-differential-analyzer-dda-baa6d6e45a4e
https://hackmd.io/@nszl/H1LXByIE2#Image-scaling-and-transformation-for-MLX
https://medium.com/@abdelhadi-salah/ray-casting-cub3d-bb5d99de742d

*Videos*

https://www.youtube.com/playlist?list=PLy4zsTUHwGJKolO9Ko_j6IStFIJnTYBul
https://www.youtube.com/watch?v=NbSee-XM7WA
https://www.youtube.com/watch?v=gYRrGTC7GtA&t=513s

*A.I usage*
A.I was used to clarify and explicit some variables found in the articles.


• An “Instructions” section containing any relevant information about compilation,
installation, and/or execution.
• A “Resources” section listing classic references related to the topic (documen-
tation, articles, tutorials, etc.), as well as a description of how AI was used —
specifying for which tasks and which parts of the project.
➠ Additional sections may be required depending on the project (e.g., usage
examples, feature list, technical choices, etc.).
Any required additions will be explicitly listed below.