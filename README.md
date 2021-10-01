# Infection Detection Protype

### Proposal:
Design and prototype a low cost device that could detect infections in patients that have received skin grafts to treat Buruli ulcers. This device should clearly tell the user if their wound have become infected so they can seek medical help. This device is to be distributed in developing countries where access to a hospital is restricted.

### Solution:
My group designed and prototyped a small, portable device that contained three UV LED’s and an RGB sensor. Using an Arduino Uno Rev3, we hooked up and programmed the components. When the button was pressed, the UV light would light up and the RGB sensor would begin picking up fluorescence. That data was outputted to a laptop where it was graphed in real-time. As it was a prototype, we tested it on known fluorescent materials like petroleum jelly, which mimics how some strains of bacteria fluoresce under a black light. The total cost of the device was around $30.

### Specs:
- Language: C++
- Device: Arduino Uno Rev3
- Peripherals: Peripherals: SparkFun RGB Light Sensor (ISL29125)

### Device:
![view 1](image_1.jpg)
![view_2](image_2.jpg)