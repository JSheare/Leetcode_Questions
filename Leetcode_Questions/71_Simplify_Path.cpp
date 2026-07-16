#include <iostream>
#include <cassert>
#include <deque>
#include <string>

std::string simplifyPath(std::string path)
{
    std::deque<std::string> dq;
    // Filling the deque with directory/file names
    for (int i{ 0 }; i < path.size(); ++i)
    {
        // Ignoring slashes
        if (path[i] == '/')
            continue;

        std::string temp;
        while (i < path.size() && path[i] != '/')
        {
            temp += path[i];
            ++i;
        }
        // Ignoring current directory
        if (temp == ".")
            continue;
        // Popping the previous directory from the deque
        else if (temp == "..")
        {
            if (!dq.empty())
                dq.pop_back();
        }
        else
            dq.push_back(temp);
    }

    // Building the simplified canonical path and returning it
    std::string newPath;
    while (!dq.empty())
    {
        newPath += '/' + dq.front();
        dq.pop_front();
    }
    if (newPath.size() == 0)
        return "/";

    return newPath;
}

#if 0
int main()
{
    // Provided test cases
    assert(simplifyPath("/home/") == "/home");

    assert(simplifyPath("/home//foo/") == "/home/foo");

    assert(simplifyPath("/home/user/Documents/../Pictures") == "/home/user/Pictures");

    assert(simplifyPath("/../") == "/");

    assert(simplifyPath("/.../a/../b/c/../d/./") == "/.../b/d");

    std::cout << "Success!\n";

    return 0;
}
#endif