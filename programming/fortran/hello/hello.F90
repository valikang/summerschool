program hello
  implicit none
  REAL             :: r = 1.5
  REAL 		   :: x = 3
  REAL             :: z
  z = x*r
  write (*,*) 'Hello world from Fortran and z is x*r = ', z
end program hello
