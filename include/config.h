#ifndef __CONFIG_H__
#define __CONFIG_H__

//#define _SHOW_EXCEPTION_HANDLER_
//#define _SHOW_TASK_SCHED_BY_YIELD_
//#define _SHOW_TASK_SCHED_ROUND_ROBIN_
#define _SHOW_TIMER_SORTED_LIST_
//#define _SHOW_MUTEX_
//#define _SHOW_SEMAPHORE_


#define _USE_BITMAP_
#define _USE_SORTED_LIST_
//#define _USE_NORMAL_LIST_


// DEBUG
#ifdef _SHOW_TIMER_SORTED_LIST_
#define _SHOW_TASK_SCHED_ROUND_ROBIN_
#define _DEBUG_SHOW_TIMER_SORTED_LIST_
#endif
#ifdef _SHOW_MUTEX_
#define _SHOW_TASK_SCHED_ROUND_ROBIN_
#define _DEBUG_SHOW_MUTEX_
#endif
#ifdef _SHOW_SEMAPHORE_
#define _SHOW_TASK_SCHED_ROUND_ROBIN_
#define _DEBUG_SHOW_SEMAPHORE_
#endif
#ifdef _SHOW_TASK_SCHED_BY_YIELD_
#define _DEBUG_SHOW_TASK_SCHED_BY_YIELD_
#endif
#ifdef _SHOW_TASK_SCHED_ROUND_ROBIN_
#define _DEBUG_SHOW_TASK_SCHED_ROUND_ROBIN_
#endif

#endif /* __CONFIG_H__ end */

