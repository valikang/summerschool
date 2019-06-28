#!/bin/bash
#SBATCH -J my_job_name
#SBATCH -o log.out
#SBATCH -e log.err
#SBATCH -n 2 
#SBATCH -p small 
#SBATCH -t 1 
#SBATCH --reservation= Summerschool
aprun -n 2 ./a.out
