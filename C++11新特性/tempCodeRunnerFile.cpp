    size_t id = 0;
    auto f1 = [&id](int param)
    {
        cout << "id:" << id << endl;
        ++id;
        ++param;
    };
    id = 42;
    f1(7);
    f1(7);
    cout << "id:" << id << endl;