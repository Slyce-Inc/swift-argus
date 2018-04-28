
public struct Size2D {
  public let width: Int
  public let height: Int

  public init(width: Int, height: Int) {
    self.width = width
    self.height = height
  }
}

public typealias EGLStreamKHR = UnsafeMutableRawPointer?