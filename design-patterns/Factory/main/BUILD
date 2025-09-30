load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

cc_library (
    name = "document",
    hdrs = ["document.h"],
)

cc_library (
    name = "textdocument",
    hdrs = ["TextDocument.h"],
    srcs = [
        "TextDocument.cc"
    ],
    deps = [
        ":document"
    ]
)

cc_library (
    name = "spreadsheet",
    hdrs = ["SpreadSheet.h"],
    srcs = [
        "SpreadSheet.cc"
    ],
    deps = [
        ":document"
    ]
)

cc_library (
    name = "application",
    hdrs = ["application.h"],
    srcs = [ "application.cc" ],
    deps = [
        ":document"
    ]
)

cc_library (
    name = "textapplication",
    hdrs = ["TextDocumentApplication.h"],
    srcs = [ "TextDocumentApplication.cc" ],
    deps = [
        ":application",
        ":textdocument"
    ]
)

cc_library (
    name = "spreadsheetapplication",
    hdrs = ["SpreadSheetApplication.h"],
    srcs = [ "SpreadSheetApplication.cc" ],
    deps = [
        ":spreadsheet",
        ":application"
    ]
)

cc_binary (
    name = "main",
    srcs = ["main.cc"],
    deps = [
        ":textapplication",
        ":spreadsheetapplication"
    ]
)