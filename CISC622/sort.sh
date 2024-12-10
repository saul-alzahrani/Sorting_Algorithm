#!/bin/bash
#SBATCH -A cis240102p        # Project ID
#SBATCH -p GPU-shared        # Select GPU-shared partition
#SBATCH -N 1                 # Request 1 node
#SBATCH -n 5                 # Request 5 cores
#SBATCH --gres=gpu:1         # Request 4 GPUs
#SBATCH -t 09:00:00          # Set maximum run time to 10 minutes
#SBATCH --mail-user=ajaffery@udel.edu   # Your email address
#SBATCH --mail-type=ALL      # Notification type for emails

module load gcc               # Load GCC module

echo "========== Compilation Start =========="

# Compile all implementations
gcc -o default default.c
echo "Compiled: default"

gcc -o interchange interchange.c
echo "Compiled: interchange"

gcc -o fusion fusion.c
echo "Compiled: fusion"

gcc -o blocking blocking.c
echo "Compiled: blocking"

gcc -o inlining inlining.c
echo "Compiled: inlining"

echo "========== Compilation Complete =========="

echo ""

echo "========== Profiling CPU Cache Metrics =========="
echo ""

echo "Profiling Default Implementation"
echo "-----------------------------------"
perf stat -e cache-misses,cache-references ./default
echo ""
echo "Default Implementation Profiling Completed"
echo ""

echo "Profiling Interchange Implementation"
echo "-----------------------------------"
perf stat -e cache-misses,cache-references ./interchange
echo ""
echo "Interchange Implementation Profiling Completed"
echo ""

echo "Profiling Fusion Implementation"
echo "-----------------------------------"
perf stat -e cache-misses,cache-references ./fusion
echo ""
echo "Fusion Implementation Profiling Completed"
echo ""

echo "Profiling Blocking Implementation"
echo "-----------------------------------"
perf stat -e cache-misses,cache-references ./blocking
echo ""
echo "Blocking Implementation Profiling Completed"
echo ""

echo "Profiling Inlining Implementation"
echo "-----------------------------------"
perf stat -e cache-misses,cache-references ./inlining
echo ""
echo "Inlining Implementation Profiling Completed"
echo ""

echo "========== CPU Cache Profiling Completed =========="