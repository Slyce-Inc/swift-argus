import libargus

public class OutputStreamSettings {
  let wrapped: UnsafeRawPointer?

  init(_ wrapped: UnsafeRawPointer) {
    self.wrapped = wrapped
  }

  deinit {
    OutputStreamSettings_destroy(wrapped)
  }
}
