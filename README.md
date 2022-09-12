To run the benchmark, you can follow the instructions below
1. modify `PARSECBenchmark-v2.1-Dedup-Taskflow/pkgs/kernels/dedup/src/Makefile`
    + you should change the taskflow include path in line 31
2. load environment variables
    + move to `PARSECBenchmark-v2.1-Dedup-Taskflow` directory
    + `source env.sh`
3. build taskflow version dedup
    + `parsecmgmt -a build -p dedup -c gcc-taskflow`
    + `-c` means the version, available ones are `gcc-taskflow`, gcc-tbb`, `gcc-pthreads`, `gcc`
    + the official version is `gcc-pthreads` and `gcc`, we add `gcc-taskflow` and gcc-tbb`
4. run taskflow version dedup
    + you may need to download download the complete version from this link, which contains input dataset
    + `parsecmgmt -a run -p dedup -c gcc-taskflow -i simlarge -n 8`
    + `-c` means which version you want to run(remember to build first)
    + `-i` means which dataset you want to run
    + `-n` means how many threads you want to use
5. uninstall
    + uninstall specific version `parsecmgmt -a uninstall -p dedup -c gcc-taskflow`
    + uninstall all `parsecmgmt -a fulluninstall -p dedup`
6. for more infomation, you can type in `parsecmgmt -a -h` or visit PARSEC official website
