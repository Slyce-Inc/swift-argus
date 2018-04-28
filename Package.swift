// swift-tools-version:4.0

import PackageDescription

let package = Package(
    name: "libArgus",
    products: [
        .library(name: "libargus", targets: ["libargus"]),
        .library(name: "Argus", targets: ["Argus"]),
    ],
    dependencies: [
    ],
    targets: [
        .target(name: "libargus", dependencies: []),
        .target(name: "Argus", dependencies: ["libargus"]),
    ]
)
