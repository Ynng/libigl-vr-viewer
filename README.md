# Libigl VR Viewer

![Screenshot of a working vr environment](https://i.imgur.com/euo8iiO.png)



The libigl vr viewer is an application developed with libigl and openvr for 3d model viewing in vr. The program has been tested and works on oculus devices (quests and rifts) along with windows. Theoretically it should work on other headsets as well but we never tried. 

The project currently has the 3d models rendering and controller tracking working properly in vr with a companion window on flat screen. It's quite basic but a lot of features can be easily implemented from there. 



## Installation

On all platforms, the vr viewer requires cmake and a modern c++
compiler on Mac OS X[¹](#¹macusers), Linux[²](#²linuxusers), or Windows[³](#³windowsusers).

SteamVR is also required for the viewer to run. 

Cloned this repository using the `--recursive`
flag (if not then issue `git submodule update --init --recursive`). 



## Compilation

Inside the project folder, run:

    mkdir build
    cd build
    cmake .. -T host=x64 -A x64



## Building

Open ```introduction.sln``` and right click on introduction in the explorer to build/debug. 

ALL_BUILD might not work, that's why the instruction above is the preferred way to get it running. 



## Addition to libigl

All of the changes we made to the libigl library are in ```include/igl/opengl```, including ```Viewer``` and ```ViewerCore```

We also made an additional directory under ```igl``` called ```openvr```, which include the ```VRApplication``` class. 

### Addition to ```ViewerCore```

```drawVR()```: the same usage as draw(), but for vr. 

```ViewerCore(igl::openvr::VRApplication *VRapp)```: overloaded viewer core constructor for vr.

### Addition to ```Viewer```

```append_vrcore```: appends a core for the right eye. 

An example usage can be found in ```main.cpp```

### ```VRApplication```

This class handles all the calculation and rendering necessary for the vr viewer, which are called by ```ViewerCore.cpp```















