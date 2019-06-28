program hello
  
	use heat
	implicit none 
	integer :: nx,ny
  real(kind=rp) :: dx,dy 
	!real(kind=rp) , dimension(:,:), allocatable :: field0
	type(field) :: myHelloField
	write (*,*)  'Give nx,ny,dx,dy:'
	read (*,*) nx,ny,dx,dy
  myHelloField%insertVariables(nx,ny,dx,dy,myHelloField)
	
  write (*,*) myHelloField
end program hello
