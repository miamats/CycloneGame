# CycloneGame
## Description
This is an interactive game, similar to the cyclone arcade game. There are two neopixels that light up green on the CPX board, this is the target area. A blue light will move through all of the neopixels, and the player must use the left button (button A) on the CPX board, to stop the blue light in the target area. 

## Inputs
The CPX slide switch turns the game on and off. Button A on the CPX board stops the blue light from moving and checks if the blue light was stopped in the target area.

## Outputs
All the neopixels light up green and a high tone plays if the blue light was stopped in target area. All the neopixels light up red and a low tone plays if the blue light wasn't stopped in target area.

## Code Explanation
I included attach intterupts for the slide switch and button A in the setup. In the loop I have an if statement that checks for the switch flag and reads the switch state. Then, I have another if statement that checks for the switch state. In that if statement, the CPX neopixels 4 and 5 light up green. Then I have a for loop moves a single blue light through all the neopixels on the CPX board. I then set my count variable equal to i within the for loop, so the count matches the blue light as it moves through all of the neopixels on the board. Next, I have another if statement that checks for the button flag. If the button flag is triggered then the CPX board is cleared and the count is delayed. Another if statement then checks if the count is stopped at 4 or 5, which then calls upon the win function, turning the entire CPX board green and a high toned sequence plays. If the count is not stopped at 4 or 5, then the lose function is called, making the CPX board light up red and play a low toned sequence. The button flag is then set back equal to 0. Finally, I have my two ISRs for the button and slide switch. 
