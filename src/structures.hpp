#pragma once
#ifndef STRUCTURES_HPP
#define STRUCTURES_HPP

#define USE_VIA_NAMESPACES

#ifndef USE_VIA_NAMESPACES
static struct EnvMessage
{
    const AnsiString
        BUDGET_INTRAMURAL,
        BUDGET_EXTRAMURAL,
        BUYERS_INTRAMURAL,
        BUYERS_EXTRAMURAL;
}
EnvelopeMessage =                                                               // AnsiString test2 = (AnsiString) EnvelopeMessage.BUDGET_INTRAMURAL;
{
    "������, ������� ����� ��������",
    "������, ������� ����� ��������",
    "�� ������, ������� ����� ��������",
    "�� ������, ������� ����� ��������"
};
static struct Period
{
    const AnsiString
        FULL,                                                                   // t_abitur_queue.term_edu = 0
        SHORT_SECOND_COURSE,                                                    // t_abitur_queue.term_edu = 1
        SHORT_THIRD_COURSE,                                                     // t_abitur_queue.term_edu = 2
        HIGH_FIRST_COURSE,                                                      // t_abitur_queue.term_edu = 3
        HIGH_SECOND_COURSE,                                                     // t_abitur_queue.term_edu = 4
        HIGH_THIRD_COURSE,                                                      // t_abitur_queue.term_edu = 5
        SHORT,
        HIGH;
}
StudyPeriod =                                                                   // AnsiString test = (AnsiString) StudyPeriod.FULL;
{
    "������ ����",
    "C���������� ���� (2 ����)",
    "C���������� ���� (3 ����)",
    "������ ����������� (1 ����)",
    "������ ����������� (2 ����)",
    "������ ����������� (3 ����)",
    "C���������� ����",
    "������ �����������"
};
#endif  // ! USE_VIA_NAMWSPACES

#endif // STRUCTURES_HPP