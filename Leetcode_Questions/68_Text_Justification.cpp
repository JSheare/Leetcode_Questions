#include <iostream>
#include <cassert>
#include <vector>
#include <string>

std::vector<std::string> fullJustify(std::vector<std::string>& words, int maxWidth)
{
    std::vector<std::string> lines;
    int start{ 0 };
    while (start < words.size())
    {
        // Determining how many words can fit on this line
        int width{ static_cast<int>(words[start].size()) };
        int end{ start + 1 };
        while (end < words.size())
        {
            int newWidth{ width + static_cast<int>(words[end].size()) + 1 };
            if (newWidth > maxWidth)
                break;

            width = newWidth;
            ++end;
        }

        // Determining the number of gaps and their sizes
        int numWords{ end - start };
        int extraSpacePer{ 0 };
        int numBiggerGaps{ 0 };
        // This is only necessary for lines that aren't the last one and have more than one word
        if (numWords > 1 && end < words.size())
        {
            int numGaps{ numWords - 1 };
            int extraSpace{ maxWidth - width };
            extraSpacePer = extraSpace / numGaps;
            numBiggerGaps = extraSpace % numGaps;
        }

        // Building the line
        std::string& line{ lines.emplace_back() };  // To avoid unnecessary copying
        line += words[start];
        for (int i{ 1 }; i < numWords; ++i)
        {
            int numSpaces{ 1 + extraSpacePer + (numBiggerGaps-- > 0) };
            line.resize(line.size() + numSpaces, ' ');
            line += words[start + i];
        }
        line.resize(maxWidth, ' ');
        start = end;
    }
    return lines;
}

#if 0
int main()
{
    // Provided test cases
    std::vector<std::string> test1{ "This", "is", "an", "example", "of", "text", "justification." };
    std::vector<std::string> answer1{ "This    is    an","example  of text","justification.  " };
    assert(fullJustify(test1, 16) == answer1);

    std::vector<std::string> test2{ "What","must","be","acknowledgment","shall","be" };
    std::vector<std::string> answer2{ "What   must   be","acknowledgment  ","shall be        " };
    assert(fullJustify(test2, 16) == answer2);

    std::vector<std::string> test3{ "Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do" };
    std::vector<std::string> answer3{ "Science  is  what we","understand      well","enough to explain to","a  computer.  Art is","everything  else  we","do                  " };
    assert(fullJustify(test3, 20) == answer3);

    std::cout << "Success!\n";

    return 0;
}
#endif