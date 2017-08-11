# honggfuzz-dharma
Integrate the dharma grammar fuzzer into honggfuzz

## Example command:
```
tools/honggfuzz/honggfuzz -f inp/ -Q -- /bin/cat ___FILE___
```