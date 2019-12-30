// swift-tools-version:5.0

import PackageDescription

let package = Package(
    name: "swift-argus",
    products: [
        .library(name: "Argus", targets: ["Argus"]),
    ],
    dependencies: [
    ],
    targets: [
        .target(name: "Argus", dependencies: ["Clibargus"]),
        .target(name: "Clibargus", dependencies: []),
    ]
)
