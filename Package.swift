// swift-tools-version:4.0

import PackageDescription

let package = Package(
    name: "Argus",
    products: [
        .library(name: "Argus", targets: ["Argus"]),
        .library(name: "Clibargus", targets: ["Clibargus"]),
    ],
    dependencies: [
    ],
    targets: [
        .target(name: "Clibargus", dependencies: []),
        .target(name: "Argus", dependencies: ["Clibargus"]),
    ]
)
