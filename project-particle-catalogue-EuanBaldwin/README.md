# Particle Catalogue - Project Guide

## Compilation

To compile the project, use the `make` command or manually enter the following line into the terminal:

```bash
g++-11 -std=c++17 -g *.cpp **/*.cpp **/**/*.cpp -o main
```

This command will generate the `main` executable in the current directory. You can run it using:

```bash
./main
```

## Particle Initialisation Guide

### Common Components

Each particle is initialised with four-momentum components:

- `E`: Energy (GeV)
- `px`, `py`, `pz`: Momentum components along the x, y, and z axes, respectively (GeV/c^2).

### Leptons

#### Electron

To create an `Electron` object:

```cpp
Electron(E, px, py, pz, antiparticle);
```

- `antiparticle`: `true` if it is a positron, `false` otherwise.

#### Muon

To create a `Muon` object:

```cpp
Muon(E, px, py, pz, antiparticle, isolated);
```

- `antiparticle`: `true` if it is an antimuon, `false` otherwise.
- `isolated`: `true` if the muon is isolated, `false` otherwise.

#### Tau

To create a `Tau` object:

```cpp
Tau(E, px, py, pz, antiparticle);
```

- `antiparticle`: `true` if it is an antitau, `false` otherwise.

#### Neutrino

To create a `Neutrino` object:

```cpp
Neutrino(E, px, py, pz, antiparticle, flavour, has_interacted);
```

- `antiparticle`: `true` if it is an antineutrino, `false` otherwise.
- `flavour`: The neutrino flavour, which can be `Neutrino_flavour::Electron`, `Neutrino_flavour::Muon`, `Neutrino_flavour::Tau`, or `Neutrino_flavour::Unknown`.
- `has_interacted`: `true` if the neutrino has interacted, `false` otherwise.

### Quarks

To create a `Quark` object:

```cpp
Quark(E, px, py, pz, antiparticle, flavour, colour);
```

- `antiparticle`: `true` if it is an antiquark, `false` otherwise.
- `flavour`: Specifies the quark flavour, for example `Quark_flavour::Up` or `Quark_flavour::Down`.
- `colour`: Represents the colour charge of the quark, for example `Colour_list::Red` or `Colour_list::Antigreen`.

### Bosons

#### Gluon

To create a `Gluon` object:

```cpp
Gluon(E, px, py, pz, antiparticle, colour, anticolour);
```

- `antiparticle`: `true` if it is an antigluon, `false` otherwise.
- `colour`: The gluon colour charge, for example `Colour_list::Red` or `Colour_list::Blue`
- `anticolour`: The complementary anti-colour charge, for example `Colour_list::AntiRed` or `Colour_list::Antiblue`

#### W and Z Bosons

To create a `W_Boson` or `Z_Boson` object:

```cpp
W_Boson(E, px, py, pz, antiparticle);
Z_Boson(E, px, py, pz);
```

- For `W_Boson`, `antiparticle` is `true` if it is a W- boson or `false` if its a W+ boson.
- Z bosons doesn't have an antiparticle.

#### Photon and Higgs Boson

To create a `Photon` or `Higgs` object:

```cpp
Photon(E, px, py, pz);
Higgs(E, px, py, pz);
```

Photons and the Higgs boson don't have antiparticles.


## Adding Decay Products to Particles

Certain particles can undergo decay processes, producing other particles as decay products. To add decay products to a particle, use the `add_decay_product` method.

### Basic Procedure

1. **Instantiate the Parent Particle**: Create the parent particle object.
2. **Create Decay Products**: Instantiate the decay products as separate particle objects.
3. **Add Decay Products**: Use the `add_decay_product` method to attach each decay product to the parent particle.
4. **Validate Decay**: Use the `validate_decay_products` method to ensure the decay products comply with conservation laws and other physical constraints.

### Example

Here is a detailed example showing how to create a Z boson and add its decay into an electron-positron pair:

```cpp
// Create a Z boson and add it to the particle container
auto z_boson = std::make_shared<Z_Boson>(1.26e+02, 1.48e+01, 3.69e+00, -8.49e+01);
container.add_particle(z_boson);

// Create decay products: electron and positron and add them to the Z boson
z_boson->add_decay_product(std::make_shared<Electron>(5.11e-04, 0, 0, 0, false)); // Electron
z_boson->add_decay_product(std::make_shared<Electron>(5.11e-04, 0, 0, 0, true));  // Positron
z_boson->validate_decay_products();

// Validate the decay process
z_boson->validate_decay_products();
```