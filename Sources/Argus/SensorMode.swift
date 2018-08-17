import Clibargus


public class SensorMode {
  let wrapped: UnsafeRawPointer?

  init(_ wrapped: UnsafeRawPointer) {
    self.wrapped = wrapped
  }

  public var inputBitDepth: Int {
    return Int(SensorMode_getInputBitDepth(wrapped))
  }

  public var outputBitDepth: Int {
    return Int(SensorMode_getOutputBitDepth(wrapped))
  }
}
