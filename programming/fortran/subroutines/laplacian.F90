module laplacian_mod
	use iso_fortran_env, only : REAL64
  implicit none
  real, parameter :: dx = 0.01, dy = 0.01

contains

  subroutine initialize(field0)
    ! TODO: implement a subroutine that initializes the input array
	  integer, parameter :: dp = REAL64
		real(dp) , dimension(:,:) :: field0
		integer :: fieldShape(2)
		integer :: nx,ny,i,j
		real   :: x,y
		fieldShape= shape(field0)
		nx= fieldShape(1)
		ny = fieldShape(2)

		y = 0.0
  		do j = 1, ny
   	  	x = 0.0
     		do i = 1, nx
        		field0(i,j) =  x**2 + y**2
      	 		 x = x + dx
    	 	end do
  	   y = y + dy
	  end do


  end subroutine initialize

  subroutine laplacian(curr, prev)
    ! TODO: insert a subroutine that computes a laplacian of the
    ! array "prev" and returns it as an array "curr"
  	integer, parameter :: dp = REAL64
    real(dp) , dimension(:,:) :: curr, prev
    integer :: fieldShape(2)
    integer :: nx,ny,i,j
    real   :: x,y
		fieldShape= shape(prev)
    nx= fieldShape(1)
    ny = fieldShape(2)


	  curr = 0.0
  	do j = 2, ny-1
   	  do i = 2, nx-1
    	    curr(i,j) = (prev(i-1,j) - 2.0*prev(i,j) + prev(i+1,j)) / dx**2 + &
    	         (prev(i,j-1) - 2.0*prev(i,j) + prev(i,j+1)) / dy**2
  	   end do
	  end do


	end subroutine laplacian

  subroutine write_field(array)
    ! TODO: write a subroutine that prints "array" on screen
		integer, parameter :: dp = REAL64
    real(dp) , dimension(:,:) :: array
		integer :: i, nx
		integer :: arrayShape(2) 
		arrayShape= shape(array)
    nx= arrayShape(1)
   


  	write(*,*) "You wanted me to print this:"
  	do i = 1,nx
     	write(*,'(*(G9.1))'), array(i,:)
  	enddo
	 
	end subroutine write_field

end module laplacian_mod
