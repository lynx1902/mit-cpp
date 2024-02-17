template <typename T> T min(const T m1, const T m2) {
  if (m1 > m2) {
    return m2;
  } else {
    return m1;
  }
}
