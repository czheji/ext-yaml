//
// Created by dengyu on 2017/5/11.
//

#include <yaml.h>
#include <stdio.h>

int main(void)
{
    FILE *file;
    yaml_parser_t parser;
    yaml_event_t event;
    yaml_document_t document;

    int done = 0;
    int count = 0;
    int error = 0;

    fflush(stdout);

    //file = fopen("domain.yml", "rb");
    file = fopen("D:\\gitZcsmart\\core-ckeys\\ext\\yaml\\tests\\domain.yml", "rb");
    yaml_parser_initialize(&parser);
    yaml_parser_set_input_file(&parser, file);

    /*while (!done)
    {
        if (!yaml_parser_parse(&parser, &event)) {
            error = 1;
            break;
        }

        event.data.

        done = (event.type == YAML_STREAM_END_EVENT);
        yaml_event_delete(&event);
        count ++;
    }*/

    while(!done)
    {
        if (!yaml_parser_load(&parser, &document)) {
            error = 1;
            break;
        }

        done = (!yaml_document_get_root_node(&document));
        yaml_document_delete(&document);

        if (!done) count ++;
    }

    yaml_parser_delete(&parser);

    fclose(file);

    printf("%s (%d events)\n", (error ? "FAILURE" : "SUCCESS"), count);
    printf("yaml domain\n");
    return 0;
}