#!/bin/bash
#SBATCH -J my_job_name
#SBATCH -o log.out
#SBATCH -e log.err
#SBATCH -n 4 
#SBATCH -p small 
#SBATCH -t 1 
#SBATCH --reservation=Summerschool
aprun -n 4 ./a.out
