# ⚙️ Solving Linear Systems of Equations Using CUDA

This project explores **parallel and distributed computing** for solving large systems of linear equations using **GPU acceleration with CUDA**.  
Four algorithms were implemented both serially (CPU) and in parallel (GPU) — **LU Decomposition**, **Gauss-Jordan**, **Gauss-Elimination**, and **Conjugate Gradient** — to compare efficiency, scalability, and computational speed.

---

## 📘 Project Overview

Modern scientific computation often requires solving systems with thousands or millions of linear equations.  
CPU-based methods become time-consuming and memory-intensive for such large matrices.  
This project leverages the parallel processing capabilities of **NVIDIA GPUs (CUDA)** to dramatically reduce execution time.

### 🧠 Objectives
- Implement and compare four classic linear-equation solvers in both serial and parallel modes.
- Analyze execution time and performance gain for increasing matrix sizes.
- Identify the most efficient algorithm for large-scale linear systems.

---

## 🧩 Implemented Algorithms

| Algorithm | Description | Serial Language | Parallel Platform |
|------------|--------------|------------------|-------------------|
| **LU Decomposition** | Factorizes matrix A into lower (L) and upper (U) matrices; solved via forward/back substitution. | C | CUDA (C++) |
| **Gauss-Jordan Elimination** | Converts the augmented matrix to reduced row-echelon form to obtain variable solutions directly. | C | CUDA (C++) |
| **Gauss-Elimination** | Converts system into upper-triangular form followed by back-substitution. | C | CUDA (C++) |
| **Conjugate Gradient Method** | Iterative algorithm for symmetric positive-definite matrices. | C | CUDA (C++) |

---

## 🧱 Methodology Summary

1. **Matrix Generation** – Random A and B matrices generated for user-defined dimensions.  
2. **Serial Implementation** – Algorithms coded in C; execution time recorded using system clock.  
3. **Parallel Implementation** – CUDA kernels written for scaling, elimination, and vector operations.  
4. **Performance Comparison** – Execution time plotted against matrix dimension for both CPU and GPU.  

**Key CUDA Kernels:**
- `scaleIndex` / `elim` – used in LU decomposition  
- `ScaleKernel`, `SubKernel` – used in Gauss-Jordan  
- `column_elimination_gpu`, `reverse_row_elimination` – used in Gauss-Elimination  
- `MatVecProductKernel`, `VecDotKernel` – used in Conjugate Gradient

---

## ⚙️ Experimental Setup

| Setup | Specification |
|--------|----------------|
| CPU | Intel Core i5-8250U / i7-7500U |
| RAM | 8–16 GB |
| GPU | NVIDIA Tesla K80 (Google Colab) |
| OS | Ubuntu 20.04 / Fedora 32 (VMs) |
| Languages | C, C++, CUDA |
| Tools | Google Colab, GCC, CUDA Toolkit |

---

## 📊 Results & Analysis

- For matrices smaller than **100 × 100**, the **CPU performed faster** due to kernel-launch overhead.  
- Beyond **500 × 500**, the **GPU outperformed CPU** significantly, with speedups up to **250×** for large matrices.  
- Among all algorithms, **Conjugate Gradient** achieved the **fastest execution** and best scalability on GPU.

| Algorithm | Best Speedup (GPU vs CPU) | Suitable Matrix Type |
|------------|----------------------------|----------------------|
| LU Decomposition | ~100× | Dense |
| Gauss-Jordan | ~120× | Dense |
| Gauss-Elimination | ~140× | General |
| **Conjugate Gradient** | **>250×** | Sparse, SPD |

---

## 📈 Performance Visualization
| Matrix Size	| CPU Time (s) | GPU Time (s) |
|------------|-----------------|----------------------|
| 100×100	| 0.0012 | 0.0028 |
| 500×500	| 0.186	| 0.009 |
| 1000×1000	| 1.62 | 0.011 |
| 5000×5000	| CPU failed | 0.08 |

Conjugate Gradient proved most efficient for large sparse systems.

---

## 🧠 Key Learnings

- GPU parallelization dramatically improves execution time for compute-intensive problems.
- Overhead dominates for smaller matrices but amortizes as workload grows.
- CUDA kernel design (block/thread structure) is critical for performance scaling.

---

## 🔮 Future Work

- Deploy as a cloud service with Docker-based GPU containers.
- Add GUI for user-friendly input and visualization.
- Extend to other domains such as FEM, CFD, and machine-learning linear solvers.
