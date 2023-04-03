<h1>
	minitalk (Unfinished)
</h1>
    
<p>
	<b>The purpose of this project is to code a small data exchange program using UNIX signals(´･ω･｀)</b><br>
</p>

<p align="center">
	
</p>

## Table of contents (Índice)
1. [Subject](#1-subject)
    - [1.1. Common Instruction](#11-common-instruction)
    - [1.2. Project instructions](#12-project-instrucions)
    - [1.3. Mandatory part](#13-mandatory-part)
    - [1.4. Bonus part](#14-bonus-part)
2. [Error control](#2-error-control)
3. [Simple plan](#3-simple-plan)

## 1. Subject
### 1.1. Common Instruction
- Functions should not finish unexpectedly (segfault, bus error, double free, etc) or have undefined behaviour.
- All memory allocated on the heap shall be released appropriately when necessary. No memory leaks shall be allowed. 
- If the statement requires it, you must deliver a Makefile that will compile your source files to the required output with the -Wall, -Werror and -Wextra flags, and of course your Makefile must not relink.
- Your Makefile has to be included at least the norm $(NAME), all, clean, fclean and re.
- To deliver the bonus of your project you must include a bonus rule in your Makefile, in which you add all the headers, libraries or functions that are forbidden in the main part of the project. The bonus must be in separate_bonus. {c/h} files. The mandatory part and the bonus are evaluated separately.
- If your project allows the use of libft, you should copy its source and its associated Makefile into a libft directory with a corresponding Makefile. Your project's Makefile of your project should first compile the library using its Makefile, and then compile the project.
- It's recommended to create test programmes for your project, although this work will not be handed in or evaluated. It will give you the opportunity to verify that your software works correctly during your evaluation and that of your peers. And yes, you are allowed to use these tests during your evaluation or that of your peers.
-　Submit your work to your assigned Git repository. Only work in your Git repository will be evaluated. If Deepthought evaluates your work, it will do so after your peers. If a bug is found during Deepthought's review, the review is over.

Who is Deepthought?

### 1.2.Project instructions
- Name your executable files "client" and "server".
- You have to turn in a Makefile which will compile your source files. It must not relink.
- You can definitely use your libft.
- You have to handle errors thoroughly. In no way your program should quit unexpectedly. (segmentation fault, bus error, double free, and so forth)
- Your program mustn't have memory leaks.
- You can have one global variable per program (one for the client and one for the server), but you will have to justify their use.
- In order to complete the mandatory part, you are allowed to use the following functions:

    - write
    - ft_printf and any functions you coded
    - signal
    - sigemptyset
    - sigaddset
    - sigaction
    - kill
    - getpid
    - malloc
    - free
    - pause
    - sleep
    - usleep
    - exit
 
### 1.3. Mandatory part
クライアントとサーバーの形で通信プログラムを作成する必要がある。
- まずサーバーを起動する必要がある。起動後、PIDを出力しなければならない。
- クライアントは2つのパラメーターを受け取る：
    - サーバーのPID。
    - 送信する文字列。
- クライアントは、パラメータとして渡された文字列をサーバーに送信しなければならない。
文字列を受信したら、サーバーはそれを印刷しなければならない。
- サーバーは、かなり速く文字列を表示しなければならない。素早くというのは、もし時間がかかりすぎると思ったら、それは長すぎるということだろう。
```
100文字表示で1秒はかかりすぎ！
```

- サーバーは、再起動する必要なく、複数のクライアントから連続して文字列を受信できなければならない。
- クライアントとサーバーの間の通信は、UNIXのシグナルのみを使用して行う。
- 使用できるシグナルは、次の2つのみ： SIGUSR1 と SIGUSR2

```
Linuxシステムは、このタイプの保留中のシグナルがある場合、シグナルをキューに入れることはない！ボーナスタイム？
```
### 1.4. Bonus part
- サーバーは、受信したすべてのメッセージに対して、クライアントにシグナルを送り返すことで確認します。
- ユニコード文字に対応！

## 3. Error control
- Number of argument is not 2 (ac != 2)
- Different number of rows or columns
- Does it have to be enclosed by 0
    - No, it can be any numbers
- Numbers are not int(IDK)
- Shouldn't accept characters
- (How many numbers of rows or columns I have to accept?)


## 4. List of signals on linux

|Number|Name|Default Action|Description|
|-----|-----|-----|-----|
|1|SIGHUP|Terminate|Terminal line hangup or parent process terminated|
|2|SIGINT|Terminate|Interrupt from keyboard(ctrl-c)|
|3|SIGQUIT|Terminate|Quit from keyboard(ctrl-\)|
|4|SIGILL|Terminate|Illegal instruction|
|5|SIGTRAP|Core|Trace trap|
|6|SIGABRT|Core|Signal from abort function|
|7|SIGBUS|Terminate|Bus error|
|8|SIGFPE|Core|Floating-point exception|
|9|SIGKILL|Terminate|Kill program|
|10|SIGUSR1|Terminate|User-defined signal 1|
|11|SIGSEGV|Core|Invalid memory reference (segfault)|
|12|SIGUSER2|Terminate|User-defined signal 2|
|13|SIGPIPE|Terminate|Write in pipe with no reader|
|14|SIGALRM|Terminate|Timer signal from alarm function|
|15|SIGTERM|Terminate|Software termination signal|
|16|SIGSTKFLT|Terminate|Stack fault on coprocessor|
|17|SIGCHLD|Ignore|Child process has stopped or terminated|
|18|SIGCONT|Ignore|Continue process if stopped|
|19|SIGSTOP|Stop|Stop signal not from terminal|
|20|SIGTSTP|Stop|Stop signal from terminal(ctrl-z)|
|21|SIGTTIN|Stop|Background process read from terminal|
|22|SIGTTOU|Stop|Background process wrote to terminal|
|23|SIGURG|Ignore|Urgent condition on socket|
|24|SIGXCPU|Terminate|CPU time limit exceeded|
|25|SIGXFSZ|Terminate|File size limit exceeded|
|26|SIGVTALRM|Terminate|Virtual timer expired|
|27|SIGPROF|Terminate|Profiling timer expired|
|28|SIGWINCH|Ignore|Window size changed|
|29|SIGIO|Terminate|I/O now possible on a descriptor|
|30|SIGPWR|Terminate|Power failure|
|31|SIGSYS|Terminate|Bad system call|

- Accept argument (ac, **av(fd)) and pass to execve function
    - Error check(ac != 2)
    - pass to main function(fdf?)
        - gnl
            - error fail memory allocation (not necessary release memory)
            - error not numbers (necessary release memory)
            - error not int (necessary release memory)
            - pass to initiation (x, y and (general?))<- if it's needed
                - x = rows(列) - check all numbers of row, check the first row and the last row
                - y = columns(行) - check all numbers of columns, check the first columns and the last columns
                - general
            - pass to function draw (x, y, z, and colour)
                - x
                - y


## 5. Functions
### pid_t
pids[] は、プロセス識別子を保持するための配列。いくつかの種類が あるが、getpid(),getppid(),fork() に関連しているものは、0 番目 の pids[PIDTYPE_PID]。
pids[PIDTYPE_PID] は、pid_link 型で、内部にstruct pid を持つ。struct pid の中には、struct upid があり、その中には getpid() 等で用いる pid を 保持するフィールド nr がある。

### sigemptyset
シグナル・セット set を、空集合に初期設定する。認識されたシグナルはすべて除外される。

sigemptyset() は、シグナル・セットを操作する関数のファミリーの一部。 シグナル・セットとは、シグナル・グループを1つのプロセスにより経過の記録を取るためのデータ・オブジェクト。例えば、プロセスにより、ブロック化しているシグナルを記録する1つのシグナル・セット、および保留中のシグナルを記録する別のシグナル・セットを作成できる。シグナル・セットは、その他の関数 (sigprocmask() など)で使用されるシグナルのグループを操作するか、またはその他の関数 (sigpending() など) で戻されるシグナル・セットを検査する ために使用される。

### sigaddset

既にsetに記録済みのシグナルのセットに、シグナルを追加する。

sigaddset() は、シグナル・セットを操作する関数のファミリーの一部。シグナル・セットとは、シグナル・グループを1つのプロセスにより経過の記録を取るためのデータ・オブジェクト。例えば、プロセスにより、ブロック化しているシグナルを記録する1つのシグナル・セット、および保留中のシグナルを記録する別のシグナル・セットを作成できる。通常、シグナル・セットは、その他の関数 (sigprocmask() など)で使用されるシグナルのグループを操作するか、またはその他の関数(sigpending() など)で戻されるシグナル・セットを検査するために使用される。

アプリケーションは、sigemptyset() または sigfillset() のどちらかを、sigset_t型のオブジェクトが他に使用される前に、各オブジェクトに対して少なくとも1回は呼び出すべきである。そのようなオブジェクトが、この方法で初期化されていないにもかかわらず、引数として pthread_sigmask()、sigaction()、sigaddset()、sigdelset()、 sigismember()、sigpending()、sigprocmask()、sigsuspend()、sigtimedwait()、sigwait()、または sigwaitinfo() のどれかに指定された場合、その結果は未定義です。

### sigaction

sigaction ()システムコールは、特定のシグナルを受信した際の プロセスの動作を変更するのに使用される。
signum には、SIGKILLとSIGSTOP以外の有効なシグナルをどれでも指定できる。
actがNULL以外であれば、シグナルsignumの新しい動作 (action)としてactが設定される。oldactがNULLでなければ、今までの動作がoldactに格納される。

sigaction 構造体は以下のような感じに定義される。

```
struct sigaction 
{
    void (*sa_handler)(int);
    void (*sa_sigaction)(int, siginfo_t *, void *);
    sigset_t sa_mask;
    int sa_flags;
    void (*sa_restorer)(void);
}
```

アーキテクチャによっては共用体 (union) が用いられており、その場合には sa_handler と sa_sigaction の両方を同時に割り当てることはできない。
sa_restorer 要素は廃止予定であり使用すべきではない。 POSIX には sa_restorer 要素に関する規定はない。
sa_handler は signum に対応する動作を指定するもので、 デフォルトの動作を行う SIG_DFL 、そのシグナルを無視する SIG_IGN 、シグナルハンドラ関数へのポインタが設定できる。 シグナルハンドラ関数の引き数は一つであり、シグナル番号が引き数として渡される。
sa_flags に SA_SIGINFO が指定された場合、 ( sa_handler ではなく) sa_sigaction により signum に対応するシグナルハンドル関数が指定される。 指定される関数は、最初の引き数としてシグナル番号を、 二番目の引き数として siginfo_t へのポインタを、三番目の引き数として (void * にキャストした) ucontext_t へのポインタを受けとる。
sa_mask は、シグナル・ハンドラ実行中に禁止 (block) するシグナルのマスクを表す。 さらに、 SA_NODEFER フラグが指定されていない場合は、ハンドラを起動するきっかけとなる シグナルにも sa_mask が適用される。
sa_flags はシグナル・ハンドラの動作を変更するためのフラグの集合を指定する。 sa_flags には、以下に示すフラグの (0個以上の) 論理和をとったものを指定する。