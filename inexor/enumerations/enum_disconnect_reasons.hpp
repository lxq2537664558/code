#pragma once


/// disconnect reasons
enum
{
    DISC_NONE = 0,
    DISC_EOP,
    DISC_LOCAL,
    DISC_KICK,
    DISC_MSGERR,
    DISC_IPBAN,
    DISC_PRIVATE,
    DISC_MAXCLIENTS,
    DISC_TIMEOUT,
    DISC_OVERFLOW,
    DISC_PASSWORD,
    DISC_NUM
};
