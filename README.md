# Simple Ballistics Simulator

Welcome to the Simple Ballistics Simulator project! This simulator is designed to help users understand basic principles of ballistics and simulate projectile motion under different conditions. Written in SFML.

> Currently Visualisation is left to be implemented - hopefully soon

## Features

- Simulate projectile motion in 3D space.
- Adjustable parameters such as initial velocity, angle of launch, and so on.
- Visualization of projectile trajectory.

## Usage (debian)

1. Clone the repository to your local machine:

```bash
git clone https://github.com/HaS33n/Project-Ballistics.git
```

2. Navigate to the project directory:

```bash
cd Project-Ballistics
```

3. Provide input for calculations (or leave default):

```bash
xdg-open calculated_ballistic_curve.bcf
```

4. Install SFML

```bash
sudo apt-get install libsfml-dev
```

5. Compile program using provided makefile:

```bash
make
```

6. Launch the simulator:

```bash
./bin/main
```

## Requirements

- Computer.
- [SFML](https://www.sfml-dev.org/)

## License

This project is licensed under the MIT License.
