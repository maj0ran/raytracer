project	('termtris', 'cpp',
	version : '0.1.0',
	default_options : ['cpp_std=c++2a',
			   'warning_level=1',
			   'werror=true',
			  ]
	)

C = 'clang'
cpp = meson.get_compiler('cpp')

add_global_arguments('-Wno-pedantic',
		     language : 'cpp')

src = ['src/main.cpp',
       'src/ray.cpp',
       'src/sphere.cpp'
      ]

incdir = include_directories('include')

subproj_math = subproject('mrn-math')
math_incdir = include_directories('subprojects/mrn-math/math/')

executable('raytracer',
	   sources: src,
	   include_directories : [ incdir, math_incdir ],
	   )

