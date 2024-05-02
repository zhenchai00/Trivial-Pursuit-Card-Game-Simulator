// These two lines prevent the file from being included multiple times in the same source file
// https://stackoverflow.com/questions/11969762/passing-an-enum-to-another-file-c
#ifndef ENUM_HPP
#define ENUM_HPP

enum AnswerType {
    NONE,
    TRUE_NEW,
    FALSE_NEW,
    SKIP,
    TRUE_DISCARD,
    FALSE_DISCARD
};

enum AnswerTypeTF { 
    DEFAULT,
    TRUE, 
    FALSE
};

#endif // ENUM_HPP