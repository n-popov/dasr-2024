StrangeMatrix transpose(StrangeMatrix m) {
    std::swap(m.first_line[1], m.second_line[0]);
    std::swap(m.first_line[2], m.third_line[0]);
    std::swap(m.third_line[1], m.second_line[2]);
    return m;
}
