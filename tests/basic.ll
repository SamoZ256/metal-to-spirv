; ModuleID = 'basic.ir'
source_filename = "basic.metal"
target datalayout = "e-p:64:64:64-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v16:16:16-v24:32:32-v32:32:32-v48:64:64-v64:64:64-v96:128:128-v128:128:128-v192:256:256-v256:256:256-v512:512:512-v1024:1024:1024-n8:16:32"
target triple = "air64-apple-macosx14.0.0"

%struct.Model = type { <2 x float>, <2 x float> }

; Function Attrs: mustprogress nofree norecurse nosync nounwind willreturn memory(none)
define <{ <4 x float>, <2 x float> }> @vertexMain(<2 x float> %0, <2 x float> %1, ptr addrspace(2) nocapture noundef readonly "air-buffer-no-alias" %2) local_unnamed_addr #0 {
  %4 = getelementptr inbounds %struct.Model, ptr addrspace(2) %2, i64 0, i32 0
  %5 = load <2 x float>, ptr addrspace(2) %4, align 8, !tbaa !33, !alias.scope !36
  %6 = getelementptr inbounds %struct.Model, ptr addrspace(2) %2, i64 0, i32 1
  %7 = load <2 x float>, ptr addrspace(2) %6, align 8, !tbaa !33, !alias.scope !36
  %8 = fmul fast <2 x float> %7, %0
  %9 = fadd fast <2 x float> %8, %5
  %10 = shufflevector <2 x float> %9, <2 x float> poison, <4 x i32> <i32 0, i32 1, i32 poison, i32 poison>
  %11 = shufflevector <4 x float> %10, <4 x float> <float poison, float poison, float 0.000000e+00, float 1.000000e+00>, <4 x i32> <i32 0, i32 1, i32 6, i32 7>
  %12 = insertvalue <{ <4 x float>, <2 x float> }> undef, <4 x float> %11, 0
  %13 = insertvalue <{ <4 x float>, <2 x float> }> %12, <2 x float> %1, 1
  ret <{ <4 x float>, <2 x float> }> %13
}

; Function Attrs: convergent mustprogress nofree nounwind willreturn memory(argmem: read)
define <4 x float> @fragmentMain(<4 x float> %0, <2 x float> %1, ptr addrspace(1) nocapture readonly %2, ptr addrspace(2) nocapture readonly %3) local_unnamed_addr #1 {
  %5 = tail call { <4 x float>, i8 } @air.sample_texture_2d.v4f32(ptr addrspace(1) nocapture readonly %2, ptr addrspace(2) nocapture readonly %3, <2 x float> %1, i1 true, <2 x i32> zeroinitializer, i1 false, float 0.000000e+00, float 0.000000e+00, i32 0) #3, !alias.scope !39
  %6 = extractvalue { <4 x float>, i8 } %5, 0
  ret <4 x float> %6
}

; Function Attrs: convergent mustprogress nofree nounwind willreturn memory(argmem: read)
declare { <4 x float>, i8 } @air.sample_texture_2d.v4f32(ptr addrspace(1) nocapture readonly, ptr addrspace(2) nocapture readonly, <2 x float>, i1, <2 x i32>, i1, float, float, i32) local_unnamed_addr #2

attributes #0 = { mustprogress nofree norecurse nosync nounwind willreturn memory(none) "approx-func-fp-math"="true" "frame-pointer"="all" "min-legal-vector-width"="64" "no-builtins" "no-infs-fp-math"="true" "no-nans-fp-math"="true" "no-signed-zeros-fp-math"="true" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "unsafe-fp-math"="true" }
attributes #1 = { convergent mustprogress nofree nounwind willreturn memory(argmem: read) "approx-func-fp-math"="true" "frame-pointer"="all" "min-legal-vector-width"="128" "no-builtins" "no-infs-fp-math"="true" "no-nans-fp-math"="true" "no-signed-zeros-fp-math"="true" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "unsafe-fp-math"="true" }
attributes #2 = { convergent mustprogress nofree nounwind willreturn memory(argmem: read) }
attributes #3 = { convergent nounwind willreturn memory(argmem: read) }

!llvm.module.flags = !{!0, !1, !2, !3, !4, !5, !6, !7, !8}
!air.vertex = !{!9}
!air.fragment = !{!18}
!air.compile_options = !{!26, !27, !28}
!llvm.ident = !{!29}
!air.version = !{!30}
!air.language_version = !{!31}
!air.source_file_name = !{!32}

!0 = !{i32 2, !"SDK Version", [2 x i32] [i32 14, i32 4]}
!1 = !{i32 1, !"wchar_size", i32 4}
!2 = !{i32 7, !"frame-pointer", i32 2}
!3 = !{i32 7, !"air.max_device_buffers", i32 31}
!4 = !{i32 7, !"air.max_constant_buffers", i32 31}
!5 = !{i32 7, !"air.max_threadgroup_buffers", i32 31}
!6 = !{i32 7, !"air.max_textures", i32 128}
!7 = !{i32 7, !"air.max_read_write_textures", i32 8}
!8 = !{i32 7, !"air.max_samplers", i32 16}
!9 = !{ptr @vertexMain, !10, !13}
!10 = !{!11, !12}
!11 = !{!"air.position", !"air.arg_type_name", !"float4", !"air.arg_name", !"pos"}
!12 = !{!"air.vertex_output", !"generated(8texCoordDv2_f)", !"air.arg_type_name", !"float2", !"air.arg_name", !"texCoord"}
!13 = !{!14, !15, !16}
!14 = !{i32 0, !"air.vertex_input", !"air.location_index", i32 0, i32 1, !"air.arg_type_name", !"float2", !"air.arg_name", !"pos"}
!15 = !{i32 1, !"air.vertex_input", !"air.location_index", i32 1, i32 1, !"air.arg_type_name", !"float2", !"air.arg_name", !"texCoord"}
!16 = !{i32 2, !"air.buffer", !"air.location_index", i32 0, i32 1, !"air.read", !"air.address_space", i32 2, !"air.struct_type_info", !17, !"air.arg_type_size", i32 16, !"air.arg_type_align_size", i32 8, !"air.arg_type_name", !"Model", !"air.arg_name", !"model"}
!17 = !{i32 0, i32 8, i32 0, !"float2", !"pos", i32 8, i32 8, i32 0, !"float2", !"scale"}
!18 = !{ptr @fragmentMain, !19, !21}
!19 = !{!20}
!20 = !{!"air.render_target", i32 0, i32 0, !"air.arg_type_name", !"float4"}
!21 = !{!22, !23, !24, !25}
!22 = !{i32 0, !"air.position", !"air.center", !"air.no_perspective", !"air.arg_type_name", !"float4", !"air.arg_name", !"pos", !"air.arg_unused"}
!23 = !{i32 1, !"air.fragment_input", !"generated(8texCoordDv2_f)", !"air.center", !"air.perspective", !"air.arg_type_name", !"float2", !"air.arg_name", !"texCoord"}
!24 = !{i32 2, !"air.texture", !"air.location_index", i32 0, i32 1, !"air.sample", !"air.arg_type_name", !"texture2d<float, sample>", !"air.arg_name", !"colorTexture"}
!25 = !{i32 3, !"air.sampler", !"air.location_index", i32 0, i32 1, !"air.arg_type_name", !"sampler", !"air.arg_name", !"colorSampler"}
!26 = !{!"air.compile.denorms_disable"}
!27 = !{!"air.compile.fast_math_enable"}
!28 = !{!"air.compile.framebuffer_fetch_enable"}
!29 = !{!"Apple metal version 32023.155 (metalfe-32023.155)"}
!30 = !{i32 2, i32 6, i32 0}
!31 = !{!"Metal", i32 3, i32 1, i32 0}
!32 = !{!"/Users/samuliak/Documents/metal-to-spirv/tests/basic.metal"}
!33 = !{!34, !34, i64 0}
!34 = !{!"omnipotent char", !35, i64 0}
!35 = !{!"Simple C++ TBAA"}
!36 = !{!37}
!37 = distinct !{!37, !38, !"air-alias-scope-arg(2)"}
!38 = distinct !{!38, !"air-alias-scopes(vertexMain)"}
!39 = !{!40, !42}
!40 = distinct !{!40, !41, !"air-alias-scope-textures"}
!41 = distinct !{!41, !"air-alias-scopes(fragmentMain)"}
!42 = distinct !{!42, !41, !"air-alias-scope-samplers"}
