# load("//cc:defs.bzl", "cc_library", "cc_test")
def _parser_library(ctx):
  print("in parser_library", ctx.label)
  # args = [ctx.outputs.out.path] + [f.path for f in ctx.files.chunks]
  # Run flex
  flex_args = ["--c++", "-o", ctx.outputs.scanner_src.path] + [f.path for f in ctx.files.lex_srcs]
  bison_args = ["--defines=" + ctx.outputs.parser_hdr.path, "--output=" + ctx.outputs.parser_src.path] +\
    [f.path for f in ctx.files.yacc_srcs]
  print("flex_args", flex_args)
  print("bison_args", bison_args)
  ctx.actions.run(
    inputs = ctx.files.lex_srcs,
    executable = "flex",
    arguments = flex_args,
    outputs = [ctx.outputs.scanner_src],
  )

  ctx.actions.run(
    inputs = ctx.files.yacc_srcs,
    executable = "bison",
    arguments = bison_args,
    outputs = [
      ctx.outputs.parser_src,
      ctx.outputs.parser_hdr,
      ctx.outputs.stack_hdr,
      ctx.outputs.location_hdr,
      ctx.outputs.position_hdr,
    ],
  )



  # cc_library(
  #   name = ctx.label.name,
  #   srcs = ctx.files.outputs,
  #   # hdrs = glob(["**/*.h"]),
  #   visibility = ["//visibility:public"]
  # )
  # _cc_library(
  #   name = ctx.label.name,
  #   srcs = ctx.files.lex_srcs,
  # )

parser_library = rule(
  implementation = _parser_library,
  attrs = {
    "lex_srcs": attr.label_list(allow_files = [".l", ".ll"], mandatory = True),
    "yacc_srcs": attr.label_list(allow_files = [".y", ".yy", ".ypp"], mandatory = True),
    # "parser_srcs": attr.output(mandatory = True),
    "flex": attr.label(
      executable = True,
      cfg = "host",
      allow_files = True,
    ),
    "bison": attr.label(
      executable = True,
      cfg = "host",
      allow_files = True,
    ),
    # "_compiler": attr.label(
    #   default = Label("//cc:cc_library")
    # )
  },
  outputs = {
    "scanner_src": "%{name}-scanner.cpp",
    "parser_src": "%{name}.tab.cpp",
    "parser_hdr": "%{name}.tab.hpp",
    "stack_hdr": "stack.hh",
    "location_hdr": "location.hh",
    "position_hdr": "position.hh",
  }
)

