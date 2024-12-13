[Mesh]
    type = GeneratedMesh
    dim = 1
[]
[Variables]
    [u]
    []
[]
[Problem]
    solve = false
[]
[Kernels]
    [dufusion]
        type = DarcyPressure
        variable = u 
        permeablity = 0.8541e-9
        viscosity = 0
    []
[]
[Executioner]
    type = Steady
[]
[Outputs]
[]
