
# Overview

The goal of this project was to learn some C++ and make a fun game. This is a soccer game designed for two players to play on the same keyboard. Player One uses the arrow keys to control the robot on the right and player two uses the aswd keys to control the robot on the left. 

## Key Challenges

Starting out, the key challenge was figuring out how to control the robot using the keyboard. Fortunately, my professor provided many examples which were very useful. By looking at the code from these examples, I was able to figure out many things. 

The next challenge was figuring out how to get the ball to bounce off of the walls. At first, the ball would hit the wall and pretty much stick to it. It was very difficult to get the ball off of the wall at this point. At first, I tried to use the method "track_velocity" but this did not work. Finally I used "omni_apply_force" and newton's third law to implement the ball bouncing off of the wall. 

After that, I faced the challenge of trying to get the ball to look like an actually soccer ball. I got an svg of a soccer ball from google images and used the browser console to get the svg code. At first, I couldn't get it to work because the svg code included many double quote marks which made it impossible to turn the whole thing into a string. I pasted the code into a notepad and used Replace to replace all of the double quotes with single quotes and was surprised to find that that actually worked. Unfortunately, the soccer ball image was massive for the game and was not in the center of the ball. I found a website that shrinks svg's and used that to make it smaller. I was able to get it to be an appropriate size, but it still was not in the center. Then I tried converting the svg to json format and using "set_style". This worked and changed the way the ball appeared but still didn't look like the svg image I was using for some reason. I left it like that because it still looks pretty good. 

## Installing and Running

These instruction assume the user has docker installed. Git clone the repo containing all of the relevant files. Start the docker image with elma and enviro installed. Use the follwing command to copy the files over to the docker image (new terminal):

```bash
docker cp C:/path/to/folder/containing/files/soccer_project <containerID>:/source
```
In the docker container:

```bash
cd soccer_project
esm init
```
This will create the necessary folders/files to compile the project. But it also overwrites the config.json file so you'll want to copy that over again.

```bash
docker cp C:/path/to/folder/containing/files/soccer_project/config.json <containerID>:/source/soccer_project
```
Now in the docker container run:

```bash
make
esm start
enviro
```
Then navigate to ```http://localhost``` and you should see the soccer field, robots, and soccer ball.

You can press ```Ctrl-C``` in the docker container to stop the enviro server.

# How to Play the Game

This is a game designed for two players to play on the same keyboard/computer. PlayerOne is on the right (green) and uses the arrow keys, PlayerTwo is on the left (orange) and uses the awsd keys. The goal is to use the robot to push the ball into the opposing player's goal. If the ball gets stuck in the corner, click the ```Reset``` button. Once a player scores, the players and ball will be teleported to the starting positions and the score will be displayed on the robot. 

# Acknowledgments

Enviro and much of the code and information used to make this game was provided by my professor Eric Klavins. The code used to style the ball was found at ```https://commons.wikimedia.org/wiki/File:Simple_Soccer_Ball.svg```
