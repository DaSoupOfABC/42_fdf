# =============================================================================
#                                FDF - Makefile
# =============================================================================

# ======================== Compiler and Flags ================================
CC      := gcc
CFLAGS  := -Wall -Wextra -Werror -g
IFLAGS  := -I./headers
LDFLAGS := -L./helpers/libft -L./helpers/minilibx-linux/minilibx-linux -lft -lmlx -lX11 -lXext -lm

# ======================== Project Name ======================================
NAME    := fdf

# ======================== Directories =======================================
SRC_DIR     := src
HEADERS_DIR := headers
HELPERS_DIR := helpers

LIBFT_DIR   := $(HELPERS_DIR)/libft
GNL_DIR     := $(HELPERS_DIR)/get_next_line
MLX_DIR     := $(HELPERS_DIR)/minilibx-linux/minilibx-linux

# ======================== Source Files ======================================
SRC         := $(shell find $(SRC_DIR) -name "*.c")
OBJ         := $(SRC:.c=.o)

GNL_SRC     := $(wildcard $(GNL_DIR)/*.c)
GNL_OBJ     := $(GNL_SRC:.c=.o)

# ======================== Libraries =========================================
LIBFT       := $(LIBFT_DIR)/libft.a
MLX_LIB     := $(MLX_DIR)/libmlx.a

# ======================== Rules =============================================


all: $(NAME)


$(NAME): $(OBJ) $(GNL_OBJ) $(LIBFT) $(MLX_LIB)
	@echo "Linking $(NAME)..."
	$(CC) $(CFLAGS) $(IFLAGS) $(OBJ) $(GNL_OBJ) -o $@ $(LDFLAGS)


%.o: %.c
	@echo "Compiling $<..."
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@


$(LIBFT):
	@echo "Building Libft..."
	@$(MAKE) -C $(LIBFT_DIR)


$(MLX_LIB):
	@echo "Building MiniLibX..."
	@$(MAKE) -C $(MLX_DIR)

clean:
	@echo "Cleaning object files..."
	@rm -f $(OBJ) $(GNL_OBJ)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MLX_DIR) clean


fclean: clean
	@echo "Removing $(NAME)..."
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean


re: fclean all

# =============================================================================
#                                PHONY RULES
# =============================================================================
.PHONY: all clean fclean re
