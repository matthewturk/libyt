# libyt
`libyt` is a C++ library for Python package [`yt`](https://yt-project.org/).  It aims to let simulation code uses [`yt`](https://yt-project.org/) to do inline-analysis, while the code is still running. In this way, we can skip the step of writing data to local disk first before doing any analysis. This greatly reduce the disk usage, and increase the temporal resolution.

The basic idea:
![](./doc/res/BasicIdea.png)

- **Implement `libyt` into your code** :arrow_right:
  - [Installation](#installation)
  - [User Guide](#user-guide)
  - [Example](#example)
- **See `libyt` working progress** :arrow_right: [Project Board](https://github.com/calab-ntu/libyt/projects/1)
- **See how `libyt` is developed** :arrow_right: [`libyt` Milestone](https://hackmd.io/@Viukb0eMS-aeoZQudVyJ2w/ryCYwu0xF)
- **Supported `yt` functionalities**:

  |       `yt` Function      | Supported | Notes                                    |
  |:------------------------:|:---------:|------------------------------------------|
  | `find_max`               | V         |                                          |
  | `ProjectionPlot`         | V         |                                          |
  | `OffAxisProjectionPlot`  | V         |                                          |
  | `SlicePlot`              | V         |                                          |
  | `OffAxisSlicePlot`       | V         |                                          |
  | `covering_grid`          | V         |                                          |
  | 1D `create_profile`      | V         |                                          |
  | 2D `create_profile`      | V         |                                          |
  | `ProfilePlot`            | V         |                                          |
  | `PhasePlot`              | V         |                                          |
  | `LinePlot`               | V         |                                          |
  | Halo Analysis            |           | Not test yet.                            |
  | Isocontours              |           | Not test yet.                            |
  | `volume_render`          | V         | Only when MPI size is even will it work. |
  | `ParticlePlot`           | X         | Generate false figure.                   |
  | `ParticleProjectionPlot` | X         | Generate false figure.                   |

## Installation
### libyt
In `/libyt/src/Makefile`, update `PYTHON_PATH` and `MPI_PATH`:
```makefile
# Your paths
############################################################
PYTHON_PATH := $(YOUR_PYTHON_PATH)
MPI_PATH := $(YOUR_MPI_PATH)
```

Compile and move `libyt.so.*` to `/libyt/lib` folder::
```bash
make clean
make
cp libyt.so* ../lib/
```

Include `libyt` header which is in `/libyt/include/libyt.h` and library in your simulation code. Make sure you are using the same `MPI_PATH` to compile `libyt` and your simulation code.

### yt
> :warning: We will submit a pull request to [`yt-project/yt`](https://github.com/yt-project/yt). This section is only for temporary. For now, you can only build from source code.

Clone [`cindytsai/yt`-`libyt` branch](https://github.com/cindytsai/yt/tree/libyt):
```bash
git clone -b libyt https://github.com/cindytsai/yt.git
```

Install using pip:
```bash
pip install .
```

## User Guide
This guide will walk you through how to implement `libyt` into your code. And how you can convert your everyday used `yt` script to do inline-analysis.
- Implement `libyt`
- [Inline Python Script](./doc/InlinePythonScript.md)

## Example
- A simple demo in [`libyt/example.cpp`](./example/example.cpp)
- Applied to simulation code:
  - [`gamer`](https://github.com/gamer-project/gamer)
    - *I'll update the links when it is merged...*
