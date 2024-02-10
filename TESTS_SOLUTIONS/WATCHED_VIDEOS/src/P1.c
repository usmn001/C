/*
 ============================================================================
 Name        : P1.c
 Author      : M USMAN
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style 
 Problem Solved : https://www.testdome.com/tests/embedded-systems-c-online-test/155 ( Watched_Videos)
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Video {
    char *name;
    int unique_views;
} Video;

typedef struct Viewer {
    char *username;
    Video *watched_videos;
    int watched_videos_size;
} Viewer;

int count_views(Viewer **viewers, int viewers_size, char *video_name)
{
    // Waiting to be implemented
	Viewer *pt1;
	int cnt=0;

	pt1 = *viewers;   // Here i am accessing address of struct instance viewer by *viewers
	                  // which is present as an element of the array of pointers viewers.

	/*  Debug Statements
	printf("Double Pointer viewers address : %p \n",viewers);
	printf("Pointer pt1 Contains Address : %p \n ",pt1);
    */
	for(int index=0;index<viewers_size;index++){
	if( (strcmp ( (pt1->watched_videos->name),(video_name) ))==0 )
	{
	cnt +=1;
	}
	pt1 = pt1+1;
	}

    return cnt;
}


int main()
{
    Video videos[] = { {.name = "Soccer", .unique_views = 500},
                       {.name = "Basketball", .unique_views = 1000} };
    Viewer viewer = {.username = "Dave", .watched_videos = videos,
                     .watched_videos_size = 2};

    Viewer *viewers[] = { &viewer };

    /* Debug Statements
     *
    printf("Viewers Array Pointer Has Address %p \n",viewers);
    printf("Viewers Array 1st Element Address %p \n",viewers[0]);
    printf("Viewer Element Address %p \n",&viewer);

    */
    printf("%d", count_views(viewers, 1, "Soccer")); /* should print 1 */
    return 0;
}

