/*
 * ============================================
 * file: main.c
 * @Author John Malliotakis (jmal@csd.uoc.gr)
 * @Version 23/10/2023
 *
 * @e-mail hy240@csd.uoc.gr
 *
 * @brief Main function
 *        for CS240 Project Phase 1,
 *        Winter Semester 2023-2024
 * @see   Compile using supplied Makefile by running: make
 * ============================================
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#include "streaming_service.h"

/* Maximum input line size */
#define MAX_LINE 1024

/*
 * Uncomment the following line to
 * enable debugging prints
 * or comment to disable it
 */
/* #define DEBUG */
#ifdef DEBUG
#define DPRINT(...) fprintf(stderr, __VA_ARGS__);
#else
#define DPRINT(...)
#endif /* DEBUG */



#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>



struct user* head=NULL;
struct new_movie *kefali=NULL;
struct movie*category_table[6];
struct user *node_guard=NULL;
struct suggested_movie *first=NULL;



void init_structures(void)
{
    for(int i=0; i<6; i++){
        category_table[i]=NULL;
    }
    node_guard = malloc(sizeof(struct user));
    head = malloc(sizeof(struct user));
    kefali= malloc(sizeof (struct new_movie));

    if(node_guard==NULL){
        printf("failed\n");
        exit(1);
    }
    node_guard->uid = -1;
    node_guard->suggestedHead = NULL;
    node_guard->suggestedTail = NULL;
    node_guard->watchHistory = NULL;
    node_guard->next = NULL;

    if(head==NULL){
        printf("failed\n");
        exit(1);
    }
    head->uid = -1;
    head->suggestedHead = NULL;
    head->suggestedTail = NULL;
    head->watchHistory = NULL;
    head->next = NULL;
    head->next=node_guard;

    if(kefali==NULL){
        printf("failed\n");
        exit(1);
    }
    kefali->info.mid= -1;
    kefali->info.year=-1;
    kefali->next=NULL;
    kefali->category=-1;


}

int register_user(int uid) {
    struct user* newNode = malloc(sizeof(struct user));
    struct user* temp = head;
    if (newNode == NULL) {
        printf("Error creating a new node.\n");
        exit(0);
    }
    while (temp->next != NULL) {
        if (temp->uid == uid) {
            return -1;
        }
        temp = temp->next;
    }
    newNode->uid = uid;
    newNode->next = head;
    head = newNode;

    printf("R <%d>\n Users = ", uid);
    temp = head;
    while (temp != NULL && temp != node_guard) {
        printf("%d, ", temp->uid);
        temp = temp->next;
    }
    printf("NULL\n");
    printf("DONE\n");
    return 0;
}


void unregister_user(int uid) {
    struct user *current_user = head->next;
    struct user *prev_user = head;

    while (current_user != NULL) {
        if (current_user->uid == uid) {
            /*Empty the user's doubly linked list of recommended movies*/
            struct suggested_movie *current_suggested = current_user->suggestedHead;
            while (current_suggested != NULL) {
                struct suggested_movie *temp = current_suggested;
                current_suggested = current_suggested->next;
                free(temp);
            }
            current_user->suggestedHead = NULL;
            current_user->suggestedTail = NULL;

            /* Empty the user's watch history stack*/
            struct movie *current_movie = current_user->watchHistory;
            while (current_movie != NULL) {
                struct movie *temp = current_movie;
                current_movie = current_movie->next;
            }
            current_user->watchHistory = NULL;
            prev_user->next = current_user->next;

            printf("U <%d>\n Users = ", uid);
            struct user *temp = head->next;
            while (temp != NULL && temp != node_guard) {
                printf("<%d>, ", temp->uid);
                temp = temp->next;
            }
            printf("DONE\n");

            return;
        }
        prev_user = current_user;
        current_user = current_user->next;
    }

    printf("User with ID %d not found.\n", uid);
}

int add_new_movie(unsigned mid, movieCategory_t category, unsigned year) {
    struct new_movie *temp=kefali;
    struct new_movie *headRef = kefali;
    while (temp != NULL) {
        if (temp->info.mid == mid) {
            printf("Movie ID %u already exists in the list. Cannot add duplicate movie.\n", mid);
            return -1;
        }
        if (temp->next == NULL || temp->next->info.mid > mid) {
            break;
        }
        temp = temp->next;
    }

    struct new_movie *newNode = malloc(sizeof(struct new_movie));
    if (newNode == NULL) {
        printf("Memory allocation failed. Unable to add a new movie.\n");
        return -1;
    }

    newNode->info.mid = mid;
    newNode->info.year = year;
    newNode->category = category;
    newNode->next = NULL;

    /* first node*/
    if (kefali==NULL || kefali->info.mid < mid){
        newNode->next = kefali;
        kefali = newNode;
        return 0;
    }
    newNode->next=temp->next;
    temp->next=newNode;

    printf("A %d , %d , %d\n New movies = " ,mid, category,year);
    while(headRef!=NULL){
        printf(" < %d, %d, %d > ",headRef->info.mid, headRef->category,headRef->info.year);
        headRef=headRef->next;
    }
    printf("\n");
    printf("DONE\n");


    return 0;
}

/* Function to categorize movies into their respective categories*/
void distribute_new_movies(void) {
    struct new_movie *p = kefali;

    while (p != NULL) {
        struct movie *newNode = malloc(sizeof(struct movie));
        if (newNode == NULL) {
            printf("Memory allocation failed. Unable to add a new movie.\n");
            return;
        }

        newNode->info.mid = p->info.mid;
        newNode->info.year = p->info.year;
        newNode->next = NULL;

        int index = p->category; /* Get the category of the current new_movie*/

        if (category_table[index] == NULL) {
            category_table[index] = newNode;
        } else {
            struct movie *current = category_table[index];
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }
        p = p->next;
    }

    printf("D\nCategorized Movies:\n");
    char *categories[] = {"Horror", "Sci-fi", "Drama", "Romance", "Documentary", "Comedy"};
    for (int i = 0; i < 6; i++) {
        printf("%s: ", categories[i]);
        struct movie *current = category_table[i];
        if (current == NULL) {
            printf("Empty\n");
            continue;
        }
        while (current != NULL) {
            printf("<%u, %u>, ", current->info.mid, current->info.year);
            current = current->next;
        }
        printf("\n");
    }
    printf("DONE\n");
}



int watch_movie(int uid, unsigned mid) {
    /* Find the movie in the category lists*/
    struct movie *current;
    struct movie *found_movie = NULL;
    for (int i = 0; i < 6; ++i) {
        current = category_table[i];
        while (current != NULL) {
            if (current->info.mid == mid) {
                found_movie = current; /* Movie found*/
                break;
            }
            current = current->next;
        }
        if (found_movie != NULL) {
            break;
        }
    }

    if (found_movie == NULL) {
        printf("Movie with ID %u not found.\n", mid);
        return -1; // Movie not found
    }

    /* Find the user in the user list*/
    struct user *found_user = head;
    while (found_user != NULL) {
        if (found_user->uid == uid) {
            /*Create a new node for the watched movie*/
            struct movie *watched_movie = malloc(sizeof(struct movie));
            if (watched_movie == NULL) {
                printf("Memory allocation failed. Unable to add the watched movie.\n");
                return -1;
            }

            /* Populate watched movie information*/
            watched_movie->info.mid = found_movie->info.mid;
            watched_movie->info.year = found_movie->info.year;
            watched_movie->next = found_user->watchHistory;
            found_user->watchHistory = watched_movie;

        }
        found_user = found_user->next;
    }
    found_user=head;
    while (found_user != NULL) {
        printf("User ID %d watch history:\n", found_user->uid);
        struct movie *watch_history = found_user->watchHistory;
        while (watch_history != NULL) {
            printf("Movie ID: %u, Year: %u\n", watch_history->info.mid, watch_history->info.year);
            watch_history = watch_history->next;
        }
        printf("\n");
        found_user = found_user->next;
    }
    printf("DONE\n");

    return 0;

}


int suggest_movies(int uid) {
    struct user *target_user = NULL;

    /* Find the target user*/
    struct user *current_user = head->next;
    while (current_user != NULL) {
        if (current_user->uid == uid) {
            target_user = current_user;
            break;
        }
        current_user = current_user->next;
    }

    if (target_user == NULL) {
        printf("User with ID %d not found.\n", uid);
        return -1;
    }

    struct suggested_movie *suggestedHead = NULL;
    struct suggested_movie *suggestedTail = NULL;
    struct suggested_movie *newnode = NULL;

    /*Iterating through each user's watch history*/
    current_user = head;
    int counter = 0;
    while (current_user != NULL && current_user->uid != -1) {
        /* Skip the target user and users without watch history*/
        if (current_user->uid != uid && current_user->watchHistory != NULL) {
            struct movie *popped_movie = current_user->watchHistory;
            current_user->watchHistory = popped_movie->next;

            /* Create a new suggested movie node*/
            newnode = malloc(sizeof(struct suggested_movie));
            if (newnode == NULL) {
                printf("Memory allocation failed. Unable to add a suggested movie.\n");
                return -1;
            }

            newnode->info = popped_movie->info;


            if (counter % 2 == 0) {
                newnode->next = suggestedHead;
                newnode->prev = NULL;
                if (suggestedHead) suggestedHead->prev = newnode;
                suggestedHead = newnode;
            } else {
                newnode->next = suggestedTail;
                newnode->prev = NULL;
                if (suggestedTail) suggestedTail->prev = newnode;
                suggestedTail = newnode;
            }
            counter++;
        } else {
            printf("Not adding UID %d\n", current_user->uid);
        }
        current_user = current_user->next;
    }

    struct suggested_movie *tmp = suggestedHead;
    while (tmp && tmp->next) tmp = tmp->next;

    if (tmp) {
        tmp->next = suggestedTail;
        suggestedTail->prev = tmp->next;
    }

    printf("Suggested movies for User ID %d:\n", uid);
    struct suggested_movie *curr = suggestedHead;

    while (curr) {
        printf("Movie ID: %d\n", curr->info.mid);
        curr = curr->next;
    }
    target_user->suggestedHead = suggestedHead;
    target_user->suggestedTail = suggestedTail;
    return 0;

}

int filtered_movie_search(int uid, movieCategory_t category1, movieCategory_t category2, unsigned year) {
    struct user *target_user = NULL;

    /*Find the target user*/
    struct user *current_user = head;
    while (current_user != NULL) {
        if (current_user->uid == uid) {
            target_user = current_user;
            break;
        }
        current_user = current_user->next;
    }

    if (target_user == NULL) {
        printf("User with ID %d not found.\n", uid);
        return -1;
    }

    /*Initialize pointers for traversing category lists*/
    struct movie *list1 = category_table[category1];
    struct movie *list2 = category_table[category2];

    printf("Filtered Suggested movies for User ID %d:\n", uid);

    /* Create a new sorted list based on the filter criteria*/
    struct suggested_movie *sorted_list = NULL;
    struct suggested_movie *last_node = NULL;

    while (list1 != NULL && list2 != NULL) {
        if (list1->info.year >= year && list1->info.mid <= list2->info.mid) {
            if (sorted_list == NULL) {
                sorted_list = malloc(sizeof(struct movie));
                last_node = sorted_list;
            } else {
                last_node->next = malloc(sizeof(struct movie));
                last_node = last_node->next;
            }

            last_node->info.year = list1->info.year;
            last_node->next = NULL;

            list1 = list1->next;
        } else if (list2->info.year >= year) {
            if (sorted_list == NULL) {
                sorted_list = malloc(sizeof(struct movie));
                last_node = sorted_list;
            } else {
                last_node->next = malloc(sizeof(struct movie));
                last_node = last_node->next;
            }

            last_node->info = list2->info;
            last_node->next = NULL;

            list2 = list2->next;
        } else {
            /* Move to the next movie in the lists*/
            if (list1->info.mid < list2->info.mid) {
                list1 = list1->next;
            } else {
                list2 = list2->next;
            }
        }
    }

    /* Check for remaining movies in category1 list*/
    while (list1 != NULL) {
        if (list1->info.year >= year) {
            if (sorted_list == NULL) {
                sorted_list = malloc(sizeof(struct movie));
                last_node = sorted_list;
            } else {
                last_node->next = malloc(sizeof(struct movie));
                last_node = last_node->next;
            }

            last_node->info = list1->info;
            last_node->next = NULL;
        }
        list1 = list1->next;
    }

    /*Check for remaining movies in category2 list*/
    while (list2 != NULL) {
        if (list2->info.year >= year) {
            if (sorted_list == NULL) {
                sorted_list = malloc(sizeof(struct movie));
                last_node = sorted_list;
            } else {
                last_node->next = malloc(sizeof(struct movie));
                last_node = last_node->next;
            }

            last_node->info = list2->info;
            last_node->next = NULL;
        }
        list2 = list2->next;
    }

    /* Merge the sorted list with the user's recommended movies list*/
    if (target_user->suggestedHead == NULL) {
        target_user->suggestedHead = sorted_list;
    } else {
        /* Find the last node in the user's suggested movies list*/
        struct suggested_movie *last_suggested = target_user->suggestedHead;
        while (last_suggested->next != NULL) {
            last_suggested = last_suggested->next;
        }
        last_suggested->next = sorted_list;
        sorted_list->prev=last_suggested;
    }

    /* Print the sorted suggested movies for the user*/
    struct suggested_movie *print_node = target_user->suggestedHead;
    while (print_node->next != NULL) {
        printf("Movie ID: %d\n", print_node->info.mid);
        print_node = print_node->next;
    }
    return 0;
}


void print_users(void){
    printf("P\nUsers:\n");
    struct user *current_user = head->next; /* Assuming head is a guard node*/
    while (current_user != NULL) {
        printf("%d:\n", current_user->uid);
        printf("   Suggested: ");
        struct suggested_movie *suggested_movie_node = current_user->suggestedHead;
        while (suggested_movie_node != NULL) {
            printf("<%d>, ", suggested_movie_node->info.mid);
            suggested_movie_node = suggested_movie_node->next;
        }
        printf("\n   Watch History: ");
        struct movie *watched_movie_node = current_user->watchHistory;
        while (watched_movie_node != NULL) {
            printf("<%d>, ", watched_movie_node->info.mid);
            watched_movie_node = watched_movie_node->next;
        }
        printf("\n");
        current_user = current_user->next;
    }
    printf("DONE\n");
}


void print_movies(void){
    printf("M\nCategorized Movies:\n");
    char *categories[] = {"Horror", "Sci-fi", "Drama", "Romance", "Documentary", "Comedy"};
    for (int i = 0; i < 6; i++) {
        printf("%s: ", categories[i]);
        struct movie *current = category_table[i];
        if (current == NULL) {
            printf("Empty\n");
            continue;
        }
        while (current != NULL) {
            printf("<%u, %u>, ", current->info.mid, current->info.year);
            current = current->next;
        }
        printf("\n");
    }
    printf("DONE\n");
}





/* Function to remove a movie from the service*/
void take_off_movie(unsigned mid) {
    /* Remove the movie from the category table*/
    for (int i = 0; i < 6; ++i) {
        struct movie *prev = NULL;
        struct movie *current = category_table[i];
        while (current != NULL) {
            if (current->info.mid == mid) {
                if (prev == NULL) {
                    category_table[i] = current->next;
                } else {
                    prev->next = current->next;
                }
                free(current);
                printf("Movie ID %u removed from Category %d list.\n", mid, i);
                break;
            }
            prev = current;
            current = current->next;
        }
    }

    /* Remove the movie from each user's recommended list*/
    struct user *current_user = head->next; /* Assuming head is the guard node*/
    while (current_user != NULL) {
        struct suggested_movie *prev = NULL;
        struct suggested_movie *current = current_user->suggestedHead;
        while (current != NULL) {
            if (current->info.mid == mid) {
                if (prev == NULL) {
                    current_user->suggestedHead = current->next;
                } else {
                    prev->next = current->next;
                }
                free(current);
                printf("Movie ID %u removed from User %d's recommended list.\n", mid, current_user->uid);
                break;
            }
            prev = current;
            current = current->next;
        }
        current_user = current_user->next;
    }
}

void destroy_structures(void)
{
	/*
	 * TODO: For a bonus
	 * empty all lists and stacks
	 * and free all memory associated
	 * with list/stack nodes here
	 */
}

int main(int argc, char *argv[])
{
	FILE *event_file;
	char line_buffer[MAX_LINE];

	if (argc != 2) {
		fprintf(stderr, "Usage: %s <input_file>\n",
				argv[0]);
		exit(EXIT_FAILURE);
	}

	event_file = fopen(argv[1], "r");
	if (!event_file) {
		perror("fopen error for event file open");
		exit(EXIT_FAILURE);
	}

	init_structures();
	while (fgets(line_buffer, MAX_LINE, event_file)) {
		char *trimmed_line;
		char event;
		int uid;
		unsigned mid, year;
		movieCategory_t category1, category2;
		/*
		 * First trim any whitespace
		 * leading the line.
		 */
		trimmed_line = line_buffer;
		while (trimmed_line && isspace(*trimmed_line))
			trimmed_line++;
		if (!trimmed_line)
			continue;
		/* 
		 * Find the event,
		 * or comment starting with #
		 */
		if (sscanf(trimmed_line, "%c", &event) != 1) {
			fprintf(stderr, "Could not parse event type out of input line:\n\t%s",
					trimmed_line);
			fclose(event_file);
			exit(EXIT_FAILURE);
		}

		switch (event) {
			/* Comment, ignore this line */
			case '#':
				break;
			case 'R':
				if (sscanf(trimmed_line, "R %d", &uid) != 1) {
					fprintf(stderr, "Event R parsing error\n");
					break;
				}
				register_user(uid);
				break;
			case 'U':
				if (sscanf(trimmed_line, "U %d", &uid) != 1) {
					fprintf(stderr, "Event U parsing error\n");
					break;
				}
				unregister_user(uid);
				break;
			case 'A':
				if (sscanf(trimmed_line, "A %u %d %u", &mid, &category1,
							&year) != 3) {
					fprintf(stderr, "Event A parsing error\n");
					break;
				}
				add_new_movie(mid, category1, year);
				break;
			case 'D':
				distribute_new_movies();
				break;
			case 'W':
				if (sscanf(trimmed_line, "W %d %u", &uid, &mid) != 2) {
					fprintf(stderr, "Event W parsing error\n");
					break;
				}
				watch_movie(uid, mid);
				break;
			case 'S':
				if (sscanf(trimmed_line, "S %d", &uid) != 1) {
					fprintf(stderr, "Event S parsing error\n");
					break;
				}
				suggest_movies(uid);
				break;
			case 'F':
				if (sscanf(trimmed_line, "F %d %d %d %u", &uid, &category1,
							&category2, &year) != 4) {
					fprintf(stderr, "Event F parsing error\n");
					break;
				}
				filtered_movie_search(uid, category1, category2, year);
				break;
			case 'T':
				if (sscanf(trimmed_line, "T %u", &mid) != 1) {
					fprintf(stderr, "Event T parsing error\n");
					break;
				}
				take_off_movie(mid);
				break;
			case 'M':
				print_movies();
				break;
			case 'P':
				print_users();
				break;
			default:
				fprintf(stderr, "WARNING: Unrecognized event %c. Continuing...\n",
						event);
				break;
		}
	}
	fclose(event_file);
	//destroy_structures();
	return 0;
}

