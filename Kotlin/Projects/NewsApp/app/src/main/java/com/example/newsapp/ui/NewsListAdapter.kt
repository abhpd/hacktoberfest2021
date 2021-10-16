package com.example.newsapp.ui

import android.media.Image
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.ImageView
import android.widget.TextView
import androidx.recyclerview.widget.RecyclerView
import com.bumptech.glide.Glide
import com.example.newsapp.R

class NewsListAdapter(private val listener : NewsItemClicked) : RecyclerView.Adapter<NewsViewHolder>() {

    private val items : ArrayList<News> = ArrayList()

    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): NewsViewHolder {
        var view : View = LayoutInflater.from(parent.context).inflate(R.layout.item_news,parent,false)
        val viewHolder = NewsViewHolder(view)
        view.setOnClickListener{
            listener.onClicked(items[viewHolder.adapterPosition])
        }
        return viewHolder
    }

    override fun onBindViewHolder(holder: NewsViewHolder, position: Int) {
        val currentItem = items[position]
        holder.newsHeading.text = currentItem.title
        Glide.with(holder.itemView.context).load(currentItem.url).into(holder.newsImage)
    }

    override fun getItemCount(): Int {
        return items.size
    }

    fun updateNews(updatedNews : ArrayList<News>) {
        items.clear()
        items.addAll(updatedNews)

        notifyDataSetChanged()
    }

}

class NewsViewHolder(itemView : View) : RecyclerView.ViewHolder(itemView) {
    val newsHeading : TextView = itemView.findViewById(R.id.newsHeading)
    val newsImage : ImageView = itemView.findViewById(R.id.newsImage)
}

interface NewsItemClicked {
    fun onClicked(item : News)
}
