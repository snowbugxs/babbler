[Mesh]
    type = GeneratedMesh
    dim = 2 
    nx = 10 
    ny = 10
[]
[Variables]
    [pressure]
    []
[]

[Kernels]
    [diffusion]
        type = DarcyPressure
        variable = pressure 
        # permeablity = 0.8541e-9
    []
[]

[Materials]
    [filter]
      type = PackedColumn # Provides permeability and viscosity of water through packed 1mm spheres
    []
[]

[BCs]
    [left]
        type = DirichletBC
        variable = pressure
        boundary = left 
        value = 0.0
    []
    [right]
        type = DirichletBC
        variable = pressure
        boundary = right 
        value = 1.0
    []
[]

[Executioner]
    type = Steady
    solve_type = PJFNK 
    petsc_options_iname = '-pc_type -pc_hypre_type'
    petsc_options_value = 'hypre boomeramg'
[]
[Outputs]
    exodus = true
[]

