import java.util.List;
import java.util.ArrayList;
import java.util.HashMap;



class MovieRentingSystem{
    
    private class MovieItem{

        int id, shop, price;
        boolean rented;
        MovieItem(int id, int shop, int price){
            this.id = id;
            this.shop = shop;
            this.price = price;
            this.rented = false;
        }

        @Override
        public String toString(){
            return "MovieItem(id = " + this.id + ", shop = " + this.shop + ", price = " + this.price + ")";
        }
    }

    HashMap<Integer, ArrayList<MovieItem>> movie_map;
    HashMap<Integer, HashMap<Integer, Integer>> price_map;
    ArrayList<MovieItem> rented_movies;


    public MovieRentingSystem(int n, int[][] entries){
        this.movie_map = new HashMap<>();
        this.rented_movies = new ArrayList<>();
        this.price_map = new HashMap<>();

        for(int[] entry : entries){
            if(!this.price_map.containsKey(entry[1])){
                this.price_map.put(entry[1], new HashMap<Integer, Integer>());
            }
            this.price_map.get(entry[1]).put(entry[0], entry[2]);

            if(!this.movie_map.containsKey(entry[1])){
                this.movie_map.put(entry[1], new ArrayList<>());
            }
            addMovieItemToMap(entry);
        }
    }

    private void addMovieItemToMap(int[] entry){
        int movie = entry[1], shop = entry[0], price = entry[2];
        MovieItem item = new MovieItem(movie, shop, price);
        if(this.movie_map.get(movie).isEmpty()){
            this.movie_map.get(movie).add(item);
            return;
        }
        int l = 0, r = this.movie_map.get(movie).size() - 1;
        while(l <= r){
            int index = (l + r) / 2;
            if(this.movie_map.get(movie).get(index).price < price){
                l = index + 1;
            }else if(this.movie_map.get(movie).get(index).price > price){
                r = index - 1;
            }else{
                if(this.movie_map.get(movie).get(index).shop < shop){
                    l = index + 1;
                }else if(this.movie_map.get(movie).get(index).shop > shop){
                    r = index - 1;
                }
            }
        }
        this.movie_map.get(movie).add(l, item);
    }

    private int searchMovieItem(int movie, int price, int shop){
        int l = 0, r = this.movie_map.get(movie).size() - 1;
        int index = (l + r) / 2;
        while(l <= r){
            index = (l + r) / 2;
            MovieItem item = this.movie_map.get(movie).get(index);
            if(item.price == price && item.shop == shop) return index;
            else{
                if(item.price < price){
                    l = index + 1;
                }else if(item.price > price){
                    r = index - 1;
                }else{
                    if(item.shop < shop) l = index + 1;
                    else if(item.shop > shop) r = index - 1;
                }
            }
        }
        return index;
    }

    private int searchMovieItemInRented(int price, int shop, int movie){
        int l = 0, r = this.rented_movies.size() - 1;
        int index = (l + r) / 2;
        while(l <= r){
            index = (l + r) / 2;
            MovieItem item = this.rented_movies.get(index);
            if(item.price < price) l = index + 1;
            else if(item.price > price) r = index - 1;
            else{
                if(item.shop < shop) l = index + 1;
                else if(item.shop > shop) r = index - 1;
                else{
                    if(item.id < movie) l = index + 1;
                    else if(item.id > movie) r = index - 1;
                    else break;
                }
            }
        }
        return index;
    }

    private void addMovieItemToRentedList(MovieItem item){
        if(this.rented_movies.isEmpty()){
            this.rented_movies.add(item);
            return;
        }
        int l = 0, r = this.rented_movies.size() - 1;
        while(l <= r){
            int index = (l + r) / 2;
            MovieItem temp = this.rented_movies.get(index);
            if(temp.price < item.price) l = index + 1;
            else if(temp.price > item.price) r = index - 1;
            else{
                if(temp.shop < item.shop) l = index + 1;
                else if(temp.shop > item.shop) r = index - 1;
                else{
                    if(temp.id < item.id) l = index + 1;
                    else if(temp.id > item.id) r = index - 1;
                }
            }
        }
        this.rented_movies.add(l, item);
    }

    public void print_rented_movies(){
        for(int i = 0; i < this.rented_movies.size(); i++){
            System.out.println(i + 1 + " " + this.rented_movies.get(i));
        }
    }

    public void print_movie_map(){
        System.out.println("{");
        for(int i : this.movie_map.keySet()){
            System.out.println(" ".repeat(4) + i + " : ");
            for(MovieItem item : this.movie_map.get(i)){
                System.out.println(" ".repeat(8) + item);
            }
        }
        System.out.println("}");
    }

    public List<Integer> search(int movie){
        List<Integer> out = new ArrayList<>();
        if(!this.price_map.containsKey(movie)) return out;
        int index = 0;
        while(out.size() < 5 && index < this.movie_map.get(movie).size()){
            out.add(this.movie_map.get(movie).get(index).shop);
            index++;
        }
        return out;
    }

    public void rent(int shop, int movie){
        this.addMovieItemToRentedList(this.movie_map.get(movie).remove(this.searchMovieItem(movie, this.price_map.get(movie).get(shop), shop)));
    }

    public void drop(int shop, int movie){
        int[] entry = {shop, movie, this.price_map.get(movie).get(shop)};
        this.addMovieItemToMap(entry);
        this.rented_movies.remove(this.searchMovieItemInRented(this.price_map.get(movie).get(shop), shop, movie));
    }


    public List<List<Integer>> report(){
        List<List<Integer>> out = new ArrayList<>();
        int index = 0;
        while(out.size() < 5 && index < this.rented_movies.size()){
            ArrayList<Integer> entry = new ArrayList<>();
            entry.add(this.rented_movies.get(index).shop);
            entry.add(this.rented_movies.get(index).id);
            out.add(entry);
            index++;
        }
        return out;
    }
}


class solution{

    public static void main(String[] args){
        int n = 3;
        int[][] entries = {{0, 1, 5}, {0, 2, 6}, {0, 3, 7}, {1, 1, 4}, {1, 2, 7}, {2, 1, 5}};
        
        MovieRentingSystem movie_system = new MovieRentingSystem(n, entries);
        for(int i : movie_system.search(1)) System.out.print(i + " ");
        System.out.println();
        movie_system.rent(0, 1);
        movie_system.rent(1, 2);
        for(List<Integer> item : movie_system.report()){
            for(int i : item) System.out.print(i + " ");
            System.out.println();
        }
        movie_system.drop(1, 2);
        for(int i : movie_system.search(2)) System.out.print(i + " ");
        System.out.println();
    }
}
