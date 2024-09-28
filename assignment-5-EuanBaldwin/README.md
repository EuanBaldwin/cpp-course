# How to compile

Either simply run the `make` command or enter the following line into the terminal:

```
g++-11 -std=c++17 -g *.cpp lepton_flavours/*.cpp -o main
```

This command will produce the following file in the same directory you're running on:

`main`

Which you can then execute in a terminal using:

`./main`


# Particle Initialisation Guide

This guide explains how to initiate each particle type.

## Electron

To create an Electron object:

```cpp
Electron(E, px, py, pz, antiparticle);
```

- `E`: Energy of the electron.
- `px`, `py`, `pz`: Momentum components along the x, y, and z axes.
- `antiparticle`: `true` if the particle is an antielectron (positron), otherwise `false`.

## Muon

To create a Muon object:

```cpp
Muon(E, px, py, pz, antiparticle, isolated);
```

- `E`: Energy of the muon.
- `px`, `py`, `pz`: Momentum components along the x, y, and z axes.
- `antiparticle`: `true` if the particle is an antimuon, otherwise `false`.
- `isolated`: `true` if the muon is isolated, otherwise `false`.

## Tau

To create a Tau object:

```cpp
Tau(E, px, py, pz, antiparticle, decay_mode);
```

- `E`: Energy of the tau.
- `px`, `py`, `pz`: Momentum components along the x, y, and z axes.
- `antiparticle`: `true` if the particle is an antitau, otherwise `false`.
- `decay_mode`: The decay mode of the tau, can be `Decay_types::Hadronic` or `Decay_types::Leptonic`.

## Neutrino

To create a Neutrino object:

```cpp
Neutrino(E, px, py, pz, antiparticle, flavour, has_interacted);
```

- `E`: Energy of the neutrino.
- `px`, `py`, `pz`: Momentum components along the x, y, and z axes.
- `antiparticle`: `true` if the particle is an antineutrino, otherwise `false`.
- `flavour`: The flavour of the neutrino, can be one of `Neutrino_flavour::Electron`, `Neutrino_flavour::Muon`, `Neutrino_flavour::Tau`, or `Neutrino_flavour::Unknown`.
- `has_interacted`: `true` if the neutrino has interacted, otherwise `false`.
