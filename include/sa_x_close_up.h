#ifndef SA_X_CLOSE_UP_H
#define SA_X_CLOSE_UP_H

#include "types.h"

boolu32 SaXCloseUpHandler(void);
void SaXCloseUpInit(void);
void SaXCloseUpVBlank(void);
void SaXCloseUpLoadingVBlank(void);
boolu32 SaXCloseUp(void);
boolu32 SaXCloseUpProcess(void);

#endif /* SA_X_CLOSE_UP_H */
