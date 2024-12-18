# C_Projet_2K24

## MQTT implementation over one week, project with Raspberry Pi

Project team: Benjamin EMEREAU and Gabriel GUILLORE

Project supervised by Anthony LOISEAU (major course).

### Project Objective
▶ Display Morse code messages on the Raspberry Pi's green LED.
▶ Messages received via MQTT (subscribe).
▶ Bonus: Daemon automatically launched at boot.

### Example:
▶ Reception of "Bonjour"
▶ Morse control: -... .- -. ..- .- ..- .-.

We need to impulse only sources codes, no .a or .exe files

## Notations:
Presence of Makefile, Cmake 
▶ comments
▶ lisibility of code and folders (coherence, logic)
▶ cleanliness
▶ response to errors (what we decided to parse and if we handle them)

# tutorial to imput your message:
send Mqtt message via this command:
mosquitto_pub -h localhost -t "morse/messages" -m "CODE MORSE"
