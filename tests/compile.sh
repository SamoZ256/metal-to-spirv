spirv-as --target-env=spv1.0 air_standard_library.spvasm -o air_standard_library.spv
spirv-val air_standard_library.spv
for f in *.metal; do
  echo "Testing $f"
  xcrun -sdk macosx metal -O2 -Wno-unused-variable -c $f -o ${f%.metal}.ir
  ../build/tools/llvm-spirv/llvm-spirv ${f%.metal}.ir -o ${f%.metal}.spv
  llvm-dis ${f%.metal}.ir -o ${f%.metal}.ll
  spirv-dis ${f%.metal}.spv -o ${f%.metal}.spvasm
  #spirv-as --target-env=spv1.0 ${f%.metal}.spvasm -o ${f%.metal}.spv
  spirv-link -o ${f%.metal}.linked.spv ${f%.metal}.spv air_standard_library.spv
  spirv-dis ${f%.metal}.linked.spv -o ${f%.metal}.linked.spvasm
  echo "Optimizing"
  spirv-opt -O ${f%.metal}.linked.spv -o ${f%.metal}.optimized.linked.spv
  spirv-dis ${f%.metal}.optimized.linked.spv -o ${f%.metal}.optimized.linked.spvasm
done
